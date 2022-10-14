#用单联表编译学生数据库


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Student {
	int id;
	char name[10];
} Student;

typedef struct LNode {
	Student stu;
	struct LNode *next;
} LNode, * LinkList;

//创建单链表
void InitLinkList(LNode *list);
//录入数据
void InsertList(LNode *list);
//展示数据
void showList(LNode *list);
//删除数据
void deleStudent(LNode *list);
//查找学生
LNode *getStudent(LNode *list);
//更新数据
void updateStudent(LNode *list);
//查找学生数据根据学号返回结点p
LNode *getStudentInform(LNode *list, int id);
//删除最后的学生数据
void deleLastStudent(LNode *list);
//插入数据  (按位插入）
void inserDate(LNode *list);
//插入数据  (按学号插入）
void inserNextDate(LNode *list);
//进行后插操作
inserFormLastById(LNode *list, int i);














int main() {
	LinkList list = (LinkList)malloc(sizeof(LNode));
	InitLinkList(list);
	while (1) {

		printf("---------------------------------------------\n");
		printf("----------------请输入序号-------------------\n");
		printf("-----------1.输入学生信息--------------------\n");
		printf("-----------2.展示学生信息--------------------\n");
		printf("-----------3.删除学生信息--------------------\n");
		printf("-----------4.查询学生信息--------------------\n");
		printf("-----------5.更新学生信息--------------------\n");
		printf("-----------6.插入学生信息--------------------\n");
		printf("-----------7.退--------出--------------------\n");
		printf("---------------------------------------------\n");
		printf("---------------------------------------------\n");

		int flag;
		scanf("%d", &flag);
		switch (flag) {
			case 0 :
				printf("正在退出");
				return;
			case 1:
				//录入数据
				InsertList(list);
				break;
			case 2:
				//展示数据
				showList(list);
				break;
			case 3:
				//删除数据
				deleStudent(list);
				break;
			case 4:
				//查找学生
				getStudent(list);
				break;

			case 5:
				//更新数据
				updateStudent(list);
				break;

			case 6:
				printf("请输入插入方式：");
				printf("1.按位置插入");
				printf("2.按学号插入");
				int i;
				scanf("%d", &i);
				if (i == 1) {
					//插入数据  (按位插入）
					inserDate(list);
				} else {
					if (i == 2) {
						//插入数据  (按学号插入）
						inserNextDate(list);
					} else
						printf("您的输入方式错误");
				}
				break;



			default:
				break;
		}
	}

	return 0;
}


//创建单链表
void InitLinkList(LNode *list) {
	list->next = NULL;
}

//录入数据
void InsertList(LNode *list) {
	LNode *r;
	r = list;
	int n;
	printf("请输入要插入的数据个数: \n ");
	scanf("%d", &n);
	printf("请输入数据: \n");
	while (n--) {
		LNode *p = (LNode *)malloc(sizeof(LNode));
		if (p == NULL) {
			return;
		}
		scanf("%d %s", &p->stu, &p ->stu.name);
		p->next = NULL;
		r->next = p;
		r = p;
	}
	printf("录入数据成功");
}

//展示数据
void showList(LNode *list) {
	if (list->next == NULL) {
		printf("对不起，您没有输入数据\n");
		return;
	}
	LNode *p = list->next;
	while (p != NULL) {
		printf("学号: %d, 姓名: %s\n", p->stu.id, p-> stu.name);
		p = p->next;
	}
}

//删除数据
void deleStudent(LNode *list) {
	if (list->next == NULL) {
		printf("对不起，您还没有输入数据\n");
		return;
	}
	printf("请输入学生学号：\n");
	int id;
	scanf("%d", &id);
	//查找学生数据根据学号返回结点p

	LNode *p = getStudentInform(list, id);
	if (p->next == NULL) {
		//删除最后的学生数据
		void deleLastStudent(LNode * list);
		return;
	}
	LNode *q = p->next;
	p->stu = p->next->stu;
	p->next = q->next;
	free(q);
	printf("删除成功!\n");
}

//查找学生数据根据学号返回结点p
LNode *getStudentInform(LNode *list, int id) {
	LNode *p = list->next;
	while (p != NULL && p->stu.id != id) {
		p = p->next;
	}
	if (p == NULL) {
		printf("您输入学号有误\n");
	}
	return p;
}

//删除最后的学生数据
void deleLastStudent(LNode *list) {
	LNode *s = list;
	LNode *pt = s->next;
	while (pt->next != NULL) {
		s = s->next;
		pt = s->next;
	}
	s->next = pt->next;
	printf("删除成功！\n");
	showList(list);
}

//查找学生
LNode *getStudent(LNode *list) {
	if (list->next == NULL) {
		printf("对不起，您还没有输入数据\n");
		return;
	}
	printf("请输入要查找的学号：\n");
	int id;
	scanf("%d", &id);
	LNode *p = getStudentInform(list, id);
	if (p == NULL) {
		printf("您输入的学号有误\n");
	} else {

		printf("查找成功！/n");
		printf("学号: %d, 姓名: %s\n", p->stu.id, p->stu.name);

	}

}

//插入数据  (按位插入）
void inserDate(LNode *list) {
	if (list->next == NULL) {
		printf("对不起，您还没有输入数据\n");
		return;
	}
	printf("请输入要插入的数据的位置: \n");
	int i;
	scanf("%d", &i);
	//进行后插操作
	inserFormLastById(list, i);

	showList(list);
}





//进行后插操作
inserFormLastById(LNode *list, int i) {
	LNode *p = list;
	int j = 0;
	while (p != NULL && j < i - 1) {
		p = p->next;
		j++;

	}
	if (p == NULL ) {
		return;
	}
	LNode *s = (LNode *)malloc(sizeof(LNode));
	printf("请输入数据:\n");
	scanf("%d %s", &p->stu, &p->stu.name);
	s->next = p->next;
	p->next = s;
	printf("插入成功  \n");
}

//插入数据  (按学号插入）
void inserNextDate(LNode *list) {
	if (list->next == NULL) {
		printf("对不起，您还没有输入数据\n");
		return;
	}
	printf("请问要在哪个学号后插入 \n");
	int id;
	scanf("%d", &id);
	LNode *p = (LNode *)malloc(sizeof(LNode));
	LNode *s = getStudentInform(list, id);
	scanf("%d %s", &p->stu, &p->stu.name);
	s->next = p->next;
	p->next = s;

	printf("插入成功 \n");



}



//更新数据
void updateStudent(LNode *list) {
	if (list->next == NULL) {
		printf("对不起，您还没有输入数据\n");
		return;
	}
	printf("请问要修改哪个学生的数据 \n");
	int id;
	scanf("%d", &id);
	LNode *p  = getStudentInform(list, id);
	printf("请输入更新的数据 \n");
	scanf("%d %s", &p->stu, &p->stu.name);


	printf("修改成功 \n");
	showList(list);



}






