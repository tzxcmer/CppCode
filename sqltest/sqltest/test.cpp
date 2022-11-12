#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>  
#include <WinSock.h>  //һ��Ҫ������� 
#include "mysql.h"    //����mysqlͷ�ļ�(һ�ַ�ʽ����vc++Ŀ¼�������ã�һ�����ļ��п�������Ŀ¼��Ȼ����������)  
#include <Windows.h>  

//�������������Ҳ�����ڹ���--������������  
#pragma comment(lib,"wsock32.lib") 
#pragma comment(lib,"libmysql.lib")

MYSQL mysql; //mysql����
MYSQL_FIELD* fd;  //�ֶ�������
char field[32][32];  //���ֶ�����ά����
MYSQL_RES* res; //����ṹ�������е�һ����ѯ�����
MYSQL_ROW column; //һ�������ݵ����Ͱ�ȫ(type-safe)�ı�ʾ����ʾ�����е���
char query[150]; //��ѯ���

bool ConnectDatabase();    	//��������  
void FreeConnect();
bool QueryDatabase1();  	//��ѯ1  
bool QueryDatabase2();  	//��ѯ2  
bool InsertData();		//��
bool ModifyData();		//��
bool DeleteData();		//ɾ
int main(int argc, char** argv)
{
	ConnectDatabase();
	QueryDatabase1();
	InsertData();
	QueryDatabase2();
	ModifyData();
	QueryDatabase2();
	DeleteData();
	QueryDatabase2();
	FreeConnect();
	return 0;
}
//�������ݿ�  
bool ConnectDatabase()
{
	//��ʼ��mysql  
	mysql_init(&mysql);  //����mysql�����ݿ�  
	const char host[] = "localhost";
	const char user[] = "root";
	const char psw[] = "tzx131359";
	const char table[] = "students";
	const int port = 3306;
	//����false������ʧ�ܣ�����true�����ӳɹ�  
	if (!(mysql_real_connect(&mysql, host, user, psw, table, port, NULL, 0)))
		//�м�ֱ����������û��������룬���ݿ������˿ںţ�����дĬ��0����3306�ȣ���������д�ɲ����ٴ���ȥ  
	{
		printf("Error connecting to database:%s\n", mysql_error(&mysql));
		return false;
	}
	else
	{
		printf("Connected...\n");
		return true;
	}
}
//�ͷ���Դ  
void FreeConnect()
{
	mysql_free_result(res);  //�ͷ�һ���������ʹ�õ��ڴ档
	mysql_close(&mysql);	 //�ر�һ�����������ӡ�
}

/***************************���ݿ����***********************************/
//��ʵ���е����ݿ����������д��sql��䣬Ȼ����mysql_query(&mysql,query)����ɣ������������ݿ�����ɾ�Ĳ�  
//��ѯ����  
bool QueryDatabase1()
{
	strcpy(query, "select * from studentinfo"); //ִ�в�ѯ��䣬�����ǲ�ѯ���У�user�Ǳ��������ü����ţ���strcpyҲ����  
	mysql_query(&mysql, "set names gbk"); //���ñ����ʽ��SET NAMES GBKҲ�У�������cmd����������  
	//����0 ��ѯ�ɹ�������1��ѯʧ��  
	if (mysql_query(&mysql, query)) {        // ִ��ָ��Ϊһ���ս�β���ַ�����SQL��ѯ��	
		printf("Query failed (%s)\n", mysql_error(&mysql));
		return false;
	}
	else {
		printf("query success\n");
	}
	//��ȡ�����  
	if (!(res = mysql_store_result(&mysql)))    //���sql�������󷵻صĽ����  
	{
		printf("Couldn't get result from %s\n", mysql_error(&mysql));
		return false;
	}

	//��ӡ��������  
	printf("number of dataline returned: %d\n", mysql_affected_rows(&mysql));

	//��ȡ�ֶε���Ϣ  
	char* str_field[32];  //����һ���ַ�������洢�ֶ���Ϣ
	for (int i = 0; i < 3; i++)   //����֪�ֶ�����������»�ȡ�ֶ��� 
	{
		str_field[i] = mysql_fetch_field(res)->name;	//����һ�������ֶνṹ�����顣
	}
	for (int i = 0; i < 3; i++)   //��ӡ�ֶ�  
		printf("%10s\t", str_field[i]);
	printf("\n");
	//��ӡ��ȡ������  
	while (column = mysql_fetch_row(res))   //����֪�ֶ���������£���ȡ����ӡ��һ��  
	{
		printf("%10s\t%10s\t%10s\n", column[0], column[1], column[2]);  //column��������  
	}
	return true;
}
bool QueryDatabase2()
{
	mysql_query(&mysql, "set names gbk");
	//����0 ��ѯ�ɹ�������1��ѯʧ��  
	if (mysql_query(&mysql, "select * from studentinfo"))        //ִ��SQL���  
	{
		printf("Query failed (%s)\n", mysql_error(&mysql));
		return false;
	}
	else
	{
		printf("query success\n");
	}
	res = mysql_store_result(&mysql);
	//��ӡ��������  
	printf("number of dataline returned: %d\n", mysql_affected_rows(&mysql));
	for (int i = 0; fd = mysql_fetch_field(res); i++)  //��ȡ�ֶ���  
		strcpy(field[i], fd->name);
	int j = mysql_num_fields(res);  // ��ȡ����  
	for (int i = 0; i < j; i++)  //��ӡ�ֶ�  
		printf("%10s\t", field[i]);
	printf("\n");
	while (column = mysql_fetch_row(res))
	{
		for (int i = 0; i < j; i++)
			printf("%10s\t", column[i]);
		printf("\n");
	}
	return true;
}

//��������  
bool InsertData()
{
	//������취ʵ���ֶ��ڿ���̨�ֶ�����ָ��  
	strcpy(query, "insert into studentinfo values ('����Ѹ',2,96);");

	if (mysql_query(&mysql, query))        //ִ��SQL���  
	{
		printf("Query failed (%s)\n", mysql_error(&mysql));
		return false;
	}
	else
	{
		printf("Insert success\n");
		return true;
	}
}

//�޸�����  
bool ModifyData()
{
	strcpy(query, "update studentinfo set score=22 where name='������'");
	if (mysql_query(&mysql, query))        //ִ��SQL���  
	{
		printf("Query failed (%s)\n", mysql_error(&mysql));
		return false;
	}
	else
	{
		printf("Insert success\n");
		return true;
	}
}
//ɾ������  
bool DeleteData()
{
	/*sprintf(query, "delete from studentinfo where id=6");*/
	char query[100];
	printf("please input the sql:\n");
	gets_s(query);  //�����ֶ�����sql���  
	if (mysql_query(&mysql, query))        //ִ��SQL���  
	{
		printf("Query failed (%s)\n", mysql_error(&mysql));
		return false;
	}
	else
	{
		printf("delete success\n");
		return true;
	}
}


