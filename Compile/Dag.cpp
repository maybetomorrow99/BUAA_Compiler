#include "dag.h"
#define IS_VAR(name) ((name[0] >= 'a' && name[0] <= 'z') || name[0] == '_')
#define IS_NUM(name) ((name[0] >= '0' && name[0] <= '9') || name[0] == '-')
#define IS_TEMP(name) (name[0] == '$')

vector<int> blockIndex;

/*
划分基本块
*/
void divideBlock() {
	blockIndex.push_back(0);
	for (unsigned int i = 0; i < quaterList.size(); i++) {
		if (quaterList[i].oper == "FUNC" || quaterList[i].oper == "LAB") {
			blockIndex.push_back(i);
		}
		else if (quaterList[i].oper == "BGT" || quaterList[i].oper == "BGE" || quaterList[i].oper == "BEQ"
			|| quaterList[i].oper == "BLE" || quaterList[i].oper == "BLT" || quaterList[i].oper == "BNE"
			|| quaterList[i].oper == "JUMP" || quaterList[i].oper == "REN" || quaterList[i].oper == "RET") {
			blockIndex.push_back(i + 1);
		}
	}
}


/*
合并LVAR类的赋值指令
TODO:验证这一步是否有必要
LI        2                   $temp1
LVAR      $temp1              b

ADD       $temp3    c         $temp4
LVAR      $temp4              c
*/
void mergeLVAR() {
	vector<Quaternary> quaterListTemp;

	for (unsigned int i = 0; i < quaterList.size(); i++) {
		if ((quaterList[i].oper == "LI" 
			|| quaterList[i].oper == "ADD" || quaterList[i].oper == "SUB"
			|| quaterList[i].oper == "MUL" || quaterList[i].oper == "DIV") 
			&& quaterList[i + 1].oper == "LVAR") {
			if (quaterList[i].res[0] == '$' && (quaterList[i].res == quaterList[i + 1].op1)) {
				quaterList[i].res = quaterList[i + 1].res;
				vector<Quaternary>::iterator it = quaterList.begin() + i + 1;
				quaterList.erase(it);
			}
		}
	}
}



map<string, int> nodeMap;
vector<Node> tree;
int nodeNum;
vector<Node> nodeOutput;

/*
查找节点表
*/
int inNodeMap(string name) {
	for (auto iter = nodeMap.begin(); iter != nodeMap.end(); ++iter) {
		if (iter->first == name) {
			return iter->second;
		}
	}
	return -1;
}


void insertNodeMap(string name, int i) {
	nodeMap[name] = i;
}


void insertTree(string name, int id) {
	Node node;
	node.name = name;
	node.id = id;
	tree.push_back(node);
}


/*
插入中间节点
*/
void insertTreeMid(string oper, string name, int id, int x, int y) {
	Node node;
	node.oper = oper;
	node.name = name;
	node.id = id;
	node.is_mid = true;
	for (unsigned int i = 0; i < tree.size(); i++) {
		if (tree[i].id == x)
			node.lchild = &tree[i];
		else if (tree[i].id == y)
			node.rchild = &tree[i];
	}
	tree.push_back(node);
}



void setParents(int child, int parent) {
	for (unsigned int i = 0; i < tree.size(); i++) {
		if (tree[i].id == child) {
			for (unsigned int j = 0; j < tree.size(); j++) {
				if (tree[j].id == parent) {
					for (unsigned int k = 0; k < tree[i].parents.size(); k++) {
						if (tree[i].parents[k].id == parent) {
							return;
						}
					}
					tree[i].parents.push_back(tree[j]);
				}
			}
		}
	}
}


void insertDAG(Quaternary curq) {
	int x = -1;
	int y = -1;
	int z = -1;
	x = inNodeMap(curq.op1);
	if (x == -1) {
		x = nodeNum++;
		if (IS_VAR(curq.op1)) {
			insertTree(curq.op1 + "$", x);
		}
		else
			insertTree(curq.op1, x);
		insertNodeMap(curq.op1, x);
	}

	y = inNodeMap(curq.op2);
	if (y == -1) {
		y = nodeNum++;
		if (IS_VAR(curq.op2)) {
			insertTree(curq.op2 + "$", y);
		}
		else
			insertTree(curq.op2, y);
		insertNodeMap(curq.op2, y);
	}

	for (unsigned int i = 0; i < tree.size(); i++) {
		if (tree[i].oper == curq.oper && tree[i].lchild != NULL && tree[i].rchild != NULL) {
			if (tree[i].lchild->id == x && tree[i].rchild->id == y) {
				z = tree[i].id;
			}
		}
	}

	if (z == -1) {
		z = nodeNum++;
		insertTreeMid(curq.oper, curq.res, z, x, y);
	}

	if (inNodeMap(curq.res) == -1) {
		insertNodeMap(curq.res, z);
	}
	else {
		insertNodeMap(curq.res, z);
	}

	setParents(x, z);
	setParents(y, z);

	//cout << curq.op1 << " " << x << "    ";
	//cout << curq.op2 << " " << y << "    ";
	//cout << curq.res << " " << z << endl;
}


void clearDAG() {
	nodeMap.clear();
	tree.clear();
	nodeNum = 0;
}




void removeParent(int child, int parent) {
	for (unsigned int i = 0; i < tree.size(); i++) {
		if (tree[i].id == child) {
			for (unsigned int j = 0; j < tree[i].parents.size(); j++) {
				if (tree[i].parents[j].id == parent) {
					tree[i].parents.erase(tree[i].parents.begin() + j);
					cout << "yeah" << endl;
				}
			}
		}
	}
}


/*
获取父节点都进入队列的中间节点n
或没有父节点的中间节点*/
int getNodeWithoutParent() {
	for (unsigned int i = 0; i < tree.size(); i++) {
		if (tree[i].parents.size() == 0) {
			cout << "chi"<<tree[i].lchild->id << tree[i].id << endl;
			cout << "name " << tree[i].name << tree[i].lchild->name << endl;
			removeParent(tree[i].lchild->id, tree[i].id);
			removeParent(tree[i].rchild->id, tree[i].id); 
			//cout << "hh" << endl;
			nodeOutput.push_back(tree[i]);
			cout << "love " << tree[i].id << endl;
			return tree[i].id;
		}
	}
}


void exportDAG() {

	int n;
	for (unsigned int i = 0; i < tree.size(); i++) {
		cout << tree[i].name;
		cout << tree[i].id << " ";
		cout << tree[i].parents.size() << endl;;

	}

	while (nodeOutput.size() < tree.size()) {
		cout << "test";
		n = getNodeWithoutParent();
		for (unsigned int i = 0; i < tree.size(); i++) {
			if (tree[i].id == n) {
				if (tree[i].lchild->parents.size() == 0) {
					removeParent(tree[i].lchild->id, tree[i].id);
					removeParent(tree[i].rchild->id, tree[i].id);
					nodeOutput.push_back(tree[i]); 
					n = tree[i].id;
				}
			}
		}
	}
	for (unsigned int i = 0; i < nodeOutput.size(); i++) {
		cout << nodeOutput[i].name << endl;
	}
}


void buildDAG() {
	bool flag = false;
	
	for (unsigned int i = 0; i < quaterList.size(); i++) {
		if (quaterList[i].oper == "MUL" || quaterList[i].oper == "ADD"
			|| quaterList[i].oper == "DIV" || quaterList[i].oper == "SUB") {
			flag = true;
			//添加节点
			insertDAG(quaterList[i]);
		}
		else if (flag) {
			//导出已有的树
			exportDAG();
			flag = false;
			clearDAG();
		}
	}
}


void dagInit() {
	mergeLVAR();

	divideBlock();

	//排序并去重
	sort(blockIndex.begin(), blockIndex.end());
	vector<int>::iterator iter = unique(blockIndex.begin(), blockIndex.end());
	blockIndex.erase(iter, blockIndex.end());


	for (unsigned int i = 0; i < blockIndex.size(); i++) {
		//cout << blockIndex[i] + 1 << endl;
	}
	//cout << "block num: " << blockIndex.size() << endl;
	//buildDAG();
}