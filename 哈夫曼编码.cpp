#include<string.h>
#include<stdlib.h>
#include<string>
#include<limits>
#include<iostream>
#include<fstream>

//http://blog.sina.com.cn/s/blog_4e2e15fd0100nyoi.html
using namespace std;
struct HuffmanNode     //哈夫曼树的一个结点
{
	int weight;
	int parent;
	int lchild, rchild;
	char sourcecode;      //存放源文字符集里的一个字符，如'a'
	string code;     //存放字符sourcecode对应的编码
};
class HuffmanTree     //哈夫曼树
{
private:
	HuffmanNode *Node;    //Node[]存放哈夫曼树  
	int LeafNum;     //哈夫曼树的叶子个数，也是源码个数
public:
	HuffmanTree();
	~HuffmanTree();
	void CreateHuffmanTree();
	void CreateHuffmanTreeFromKeyboard();
	void CreateHuffmanTreeFromFile();
	void Encoder();
	void Decoder();
	void PrintCodeFile();
	void PrintHuffmanTree();
	void PrintHuffmanTree_aoru(int T, int layer = 1);
};


//////////////////////////////////////////////////////////////////////////////
// 构造函数
// 函数功能：初始化哈夫曼树
//函数参数：无
//参数返回值：无
HuffmanTree::HuffmanTree()
{
	Node = NULL;
	LeafNum = 0;
}
//////////////////////////////////////////////////////////////////////////////
// 析构函数
// 函数功能：将哈夫曼的数组的空间释放
//函数参数：无
//参数返回值：无
HuffmanTree::~HuffmanTree()
{
	delete[] Node;  //http://blog.csdn.net/hazir/article/details/21413833 (关于delete[]的用法详解)
}
//////////////////////////////////////////////////////////////////////////////
// 建立哈夫曼树函数
// 函数功能：建立哈夫曼树（调用键盘建立哈夫曼树或调用从文件建立哈夫曼树的函数）
//函数参数：无
//参数返回值：无
void HuffmanTree::CreateHuffmanTree()
{
	char Choose;
	cout << "你要从文件中读入哈夫曼树(按1)，还是从键盘输入哈夫曼树(按2)？";
	cin >> Choose;
	if (Choose == '2') {     //键盘输入建立哈夫曼树
		CreateHuffmanTreeFromKeyboard();
	}//choose=='2'
	else {      //从哈夫曼树文件hfmTree.dat中读入信息并建立哈夫曼树
		CreateHuffmanTreeFromFile();
	}
}
//////////////////////////////////////////////////////////////////////////////
// 从键盘建立哈夫曼树函数
// 函数功能：从键盘建立哈夫曼树
//函数参数：无
//参数返回值：无
void HuffmanTree::CreateHuffmanTreeFromKeyboard(){
	int Num;
	cout << "\n请输入源码字符集个数：";
	cin >> Num;
	if (Num <= 1) {
		cout << "无法建立少于2个叶子结点的哈夫曼树。\n\n";
		return;
	}
	LeafNum = Num;
	Node = new HuffmanNode[2 * Num - 1];
	for (int i = 0; i<Num; i++) {//读入哈夫曼树的叶子结点信息
		cout << "请输入第" << i + 1 << "个字符值";
		getchar();
		Node[i].sourcecode = getchar();  //源文的字符存入字符数组Info[]
		getchar();
		cout << "请输入该字符的权值或频度";
		cin >> Node[i].weight; //源文的字符权重存入Node[].weight      
		Node[i].parent = -1;
		Node[i].lchild = -1;
		Node[i].rchild = -1;
		Node[i].code = "\0";
	}

	for (int j = Num; j<2 * Num - 1; j++) {//循环建立哈夫曼树内部结点
		int pos1, pos2;
		int max1, max2;
		pos2 = pos1 = j;
		max2 = max1 = numeric_limits<int>::max();  //http://blog.163.com/wujiaxing009@126/blog/static/7198839920124135147911/  (详解)
		//在所有子树的根结点中，选权重最小的两个根结点，pos1最后应指向权重最小的根结点的下标
		//pos2最后应指向权重第二小的根结点的下标      
		//max1存放当前找到的权重最小的根结点的权重
		//max2存放当前找到的权重第二小的根结点的权重

		for (int k = j - 1; k >= 0; k--) {
			if (Node[k].parent == -1){//如果是某棵子树的根结点
				if (Node[k].weight<max1){ //发现比当前最大值还大的权重
					max2 = max1;
					max1 = Node[k].weight;
					pos2 = pos1;
					pos1 = k;
				}
				else
				if (Node[k].weight<max2){ //发现比当前次大值还大的次大权重
					max2 = Node[k].weight;
					pos2 = k;
				}
			}//if (Node[j].parent==-1)
		} //for

		//在下标i处新构造一个哈夫曼树的内部结点，其左、右孩子就是以上pos1、pos2所指向的结点
		Node[pos1].parent = j;
		Node[pos2].parent = j;
		Node[j].lchild = pos1;
		Node[j].rchild = pos2;
		Node[j].parent = -1;
		Node[j].weight = Node[pos1].weight + Node[pos2].weight;
	} //for

	//产生所有叶子结点中字符的编码
	for (int m = 0; m<Num; m++) {
		//产生Node[i].sourcecode的编码，存入Node[i].code中
		int j = m;
		int j1;
		while (Node[j].parent != -1) { //从叶结点开始往根结点走，每往上走一层，就产生一位编码存入code[]
			j1 = Node[j].parent;
			if (Node[j1].lchild == j)
				Node[m].code.insert(0, "0");
			else
				Node[m].code.insert(0, "1");
			j = j1;
		}
	}

	cout << "哈夫曼树已成功构造完成。\n";

	//把建立好的哈夫曼树写入文件hfmTree.dat
	char ch;
	cout << "是否要替换原来的哈夫曼树文件(Y/N):";
	cin >> ch;
	if (ch != 'y'&&ch != 'Y') return;
	ofstream fop;
	fop.open("hfmTree.dat", ios::out | ios::binary | ios::trunc); //打开文件
	if (fop.fail())  {
		cout << "\n哈夫曼树文件打开失败，无法将哈夫曼树写入hfmTree.dat文件。\n";
		return;
	}
	fop.write((char*)&Num, sizeof(Num)); //先写入哈夫曼树的叶子结点个数
	for (int n = 0; n<2 * Num - 1; n++) { //最后写入哈夫曼树的各个结点（存储在Node[]中）
		fop.write((char*)&Node[n], sizeof(Node[n]));
		flush(cout);
	}
	fop.close(); //关闭文件
	cout << "\n哈夫曼树已成功写入hfmTree.dat文件。\n";
}
//////////////////////////////////////////////////////////////////////////////
// 从文件建立哈夫曼树函数
// 函数功能：从文件建立哈夫曼树
//函数参数：无
//参数返回值：无
void HuffmanTree::CreateHuffmanTreeFromFile(){
	ifstream fip;
	fip.open("hfmTree.dat", ios::binary | ios::in);
	if (fip.fail())  {
		cout << "哈夫曼树文件hfmTree.dat打开失败，无法建立哈夫曼树。\n";
		return;
	}
	fip.read((char*)&LeafNum, sizeof(LeafNum));
	if (LeafNum <= 1) {
		cout << "哈夫曼树文件中的数据有误，叶子结点个数少于2个，无法建立哈夫曼树。\n";
		fip.close();
		return;
	}
	Node = new HuffmanNode[2 * LeafNum - 1];
	for (int i = 0; i<2 * LeafNum - 1; i++)
		fip.read((char*)&Node[i], sizeof(Node[i]));
	fip.close();
	cout << "哈夫曼树已从文件成功构造完成。\n";
}
//////////////////////////////////////////////////////////////////////////////
//  编码函数
//  函数功能：为哈夫曼树编码
//函数参数：无
//参数返回值：无
void HuffmanTree::Encoder()
{
	if (Node == NULL) {    //内存没有哈夫曼树，则从哈夫曼树文件hfmTree.dat中读入信息并建立哈夫曼树
		CreateHuffmanTreeFromFile();
		if (LeafNum <= 1) {
			cout << "内存无哈夫曼树。操作撤销。\n\n";
			return;
		}
	}//if

	char *SourceText;    //字符串数组，用于存放源文     
	//让用户选择源文是从键盘输入，还是从源文文件ToBeTran.txt中读入
	char Choose;
	cout << "你要从文件中读入源文(按1)，还是从键盘输入源文(按2)？";
	cin >> Choose;
	if (Choose == '1') {
		ifstream fip1("ToBeTran.txt");
		if (fip1.fail())    {
			cout << "源文文件打开失败!无法继续执行。\n";
			return;
		}
		char ch;
		int k = 0;
		while (fip1.get(ch)) k++;     //第一次读文件只统计文件中有多少个字符，将字符数存入k
		fip1.close();

		SourceText = new char[k + 1];     //申请存放源文的字符数组空间
		ifstream fip2("ToBeTran.txt");    //第二次读源文文件，把内容写入SourceText[]
		k = 0;
		while (fip2.get(ch)) SourceText[k++] = ch;
		fip2.close();
		SourceText[k] = '\0';
	}
	else {     //从键盘输入源文
		string SourceBuff;
		cin.ignore();
		cout << "请输入需要编码的源文(可输入任意长，按回车键结束):\n";
		getline(cin, SourceBuff, '\n');
		int k = 0;
		while (SourceBuff[k] != '\0')
			k++;
		SourceText = new char[k + 1];
		k = 0;
		while (SourceBuff[k] != '\0') {
			SourceText[k] = SourceBuff[k];
			k++;
		}
		SourceText[k] = '\0';
	}
	cout << "需编码的源文为：";
	cout << SourceText << endl;


	//开始译码
	ofstream fop("CodeFile.dat", ios::trunc);    //打开码文存放文件   

	int k = 0;
	while (SourceText[k] != '\0')      //源文串中从第一个字符开始逐个编码       
	{
		int i;
		for (i = 0; i<LeafNum; i++){     //找到当前要编码的源文的字符在哈夫曼树Node[]中的下标
			if (Node[i].sourcecode == SourceText[k]) {    //将对应编码写入码文文件
				fop << Node[i].code;
				break;
			};
		}
		if (i >= LeafNum) {
			cout << "源文中存在不可编码的字符。无法继续执行。\n" << endl;
			fop.close();
			return;
		}

		k++;     //源文串中的字符后移一个
	}
	fop.close();
	cout << "已完成编码，码文已写入文件CodeFile.dat中。\n\n";
}
//////////////////////////////////////////////////////////////////////////////
//  译码函数
//  函数功能：对哈夫曼树进行译码
//函数参数：无
//参数返回值：无
void HuffmanTree::Decoder()
{

	//如果内存没有哈夫曼树，则从哈夫曼树文件hfmTree.dat中读入信息并建立哈夫曼树
	if (Node == NULL)
	{
		CreateHuffmanTreeFromFile();
		if (LeafNum <= 1) {
			cout << "内存无哈夫曼树。操作撤销。\n\n";
			return;
		}
	}

	//将码文从文件CodeFile.dat中读入 CodeStr[]
	ifstream fip1("CodeFile.dat");
	if (fip1.fail()) {
		cout << "没有码文，无法译码。\n";
		return;
	}

	char* CodeStr;
	int k = 0;
	char ch;
	while (fip1.get(ch)){
		k++;
	}
	fip1.close();
	CodeStr = new char[k + 1];
	ifstream fip2("CodeFile.dat");
	k = 0;
	while (fip2.get(ch))
		CodeStr[k++] = ch;
	fip2.close();
	CodeStr[k] = '\0';

	cout << "经译码得到的源文为：";
	ofstream fop("TextFile.dat");

	int j = LeafNum * 2 - 1 - 1;    //j指向哈夫曼树的根     

	int i = 0;     //码文从第一个符号开始，顺着哈夫曼树由根下行，按码文的当前符号决定下行到左孩子还是右孩子
	while (CodeStr[i] != '\0') {     //下行到哈夫曼树的叶子结点处，则译出叶子结点对应的源文字符
		if (CodeStr[i] == '0')
			j = Node[j].lchild;
		else
			j = Node[j].rchild;
		if (Node[j].rchild == -1) {    //因为哈夫曼树没有度为1的结点，所以此条件等同于Node[j]为叶结点
			cout << Node[j].sourcecode;     //屏幕输出译出的一个源文字符   
			fop << Node[j].sourcecode;
			j = LeafNum * 2 - 1 - 1;     //j再指向哈夫曼树的根       
		}
		i++;
	}
	fop.close();

	cout << "\n译码成功且已存到文件TextFile.dat中。\n\n";
}
//////////////////////////////////////////////////////////////////////////////
//  输出码文函数
//  函数功能：从文件中输出哈夫曼树的码文
//函数参数：无
//参数返回值：无
void HuffmanTree::PrintCodeFile()
{
	char ch;
	int i = 1;
	ifstream fip("CodeFile.dat");
	ofstream fop("CodePrin.dat");
	if (fip.fail())
	{
		cout << "没有码文文件，无法显示码文文件内容。\n";
		return;
	}
	while (fip.get(ch))
	{
		cout << ch;
		fop << ch;
		if (i == 50)
		{
			cout << endl;
			fop << endl;
			i = 0;
		}
		i++;
	}
	cout << endl;
	fop << endl;
	fip.close();
	fop.close();
}
//////////////////////////////////////////////////////////////////////////////
//  输出函数
//  函数功能：从内存或文件中直接输出哈夫曼树
//函数参数：无
//参数返回值：无
void HuffmanTree::PrintHuffmanTree()
{
	//如果内存没有哈夫曼树，则从哈夫曼树文件hfmTree.dat中读入信息并建立哈夫曼树
	if (Node == NULL)
	{
		CreateHuffmanTreeFromFile();
		if (LeafNum <= 1) {
			cout << "内存无哈夫曼树。操作撤销。\n\n";
			return;
		}
	}

	ofstream fop("TreePrint.dat", ios_base::trunc);
	fop.close();
	PrintHuffmanTree_aoru(2 * LeafNum - 1 - 1);
	return;
}
//////////////////////////////////////////////////////////////////////////////
//  凹入法输出函数
//  函数功能：用凹入法输出哈夫曼树
//函数参数：无
//参数返回值：无
void HuffmanTree::PrintHuffmanTree_aoru(int T, int layer){
	//凹入表示法：
	//  左子树
	// 根
	//  右子树

	if (T != -1){     //如果是非空二叉树
		//递归输出左子树
		PrintHuffmanTree_aoru(Node[T].lchild, layer + 1);    //输出根
		ofstream fop("TreePrint.dat", ios_base::app);

		cout << endl;
		fop << endl;
		for (int i = 0; i<layer * 5; i++) {    //按layer输出空格
			cout << " ";
			fop << " ";
		}
		if (Node[T].lchild == -1){    //叶结点
			cout << Node[T].sourcecode << Node[T].weight << "(" << Node[T].code << ")" << endl;
			fop << Node[T].sourcecode << Node[T].weight << "(" << Node[T].code << ")" << endl;
		}
		else {    //内部结点
			cout << Node[T].weight << endl;
			fop << Node[T].weight << endl;
		}
		fop.close();    //递归输出右子树
		PrintHuffmanTree_aoru(Node[T].rchild, layer + 1);
	}
}
int main(){

	HuffmanTree huftree;
	char Choose;
	while (1){
		cout << "\n**********************欢迎使用哈夫曼编码/译码系统**********************\n";
		cout << "* 您可以进行以下操作:                                                 *\n";
		cout << "* 1.建立哈夫曼树                                                      *\n";
		cout << "* 2.编码(源文已在文件ToBeTran中，或键盘输入)                          *\n";
		cout << "* 3.译码(码文已在文件CodeFile中)                                      *\n";
		cout << "* 4.显示码文                                                          *\n";
		cout << "* 5.显示哈夫曼树                                                      *\n";
		cout << "* 6.退出                                                              *\n";
		cout << "***********************************************************************\n";
		cout << "请选择一个操作:";
		cin >> Choose;
		switch (Choose)
		{
		case '1':
			huftree.CreateHuffmanTree();
			break;
		case '2':
			huftree.Encoder();
			break;
		case '3':
			huftree.Decoder();
			break;
		case '4':
			huftree.PrintCodeFile();
			break;
		case '5':
			huftree.PrintHuffmanTree();
			break;
		case '6':
			cout << "\n**********************感谢使用本系统!*******************\n\n";
			system("pause");
			return 0;
		}//switch
	}//while
}//main