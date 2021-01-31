#define _CRT_SECURE_NO_WARNINGS
//#include "pch.h"
#include <mysql.h>
#include <stdio.h>
#include <winsock.h>
#include <iostream>
#include <Windows.h>
#include <stdlib.h>

using namespace std;
MYSQL mysql;	//声明为全局变量
MYSQL_RES* result;


int create_customer_table()
{
	char yn[2];
	result = mysql_list_tables(&mysql, "customer");//删除表
	unsigned int rows = mysql_num_rows(result);
	mysql_free_result(result);
	if (rows > 0)
	{
		printf("The course table already exists. Do you want to delete it?\n");
		printf("Delete the table?(y--yes,n--no):");
		scanf("%s", &yn);
		if (yn[0] == 'y' || yn[0] == 'Y')	//考虑大小写
		{
			if (!mysql_query(&mysql, "drop table customer;"))
				printf("drop table customer successfully!\n");
			else
				printf("error:drop table customer failed.\n");
		}
		else  //使用原来的表,exit directly
			return 0;
	}
	int num = mysql_query(&mysql, "create table customer(customer_ID char(5) primary key,customer_name char(20),customer_sex char(4), customer_phone char(15)) engine=innodb;");
	if (num == 0)
		printf("create table customer successully!\n\n");
	else
		printf("ERROR: create table customer\n\n");
	return 0;
}

int create_industry_table()
{
	char yn[2];
	result = mysql_list_tables(&mysql, "industry");//删除表
	unsigned int rows = mysql_num_rows(result);
	mysql_free_result(result);
	if (rows > 0)
	{
		printf("The industry table already exists. Do you want to delete it?\n");
		printf("Delete the table?(y--yes,n--no):");
		scanf("%s", &yn);
		if (yn[0] == 'y' || yn[0] == 'Y')	//考虑大小写
		{
			if (!mysql_query(&mysql, "drop table industry;"))
				printf("drop table industry successfully!\n");
			else
				printf("error:drop table industry failed.\n");
		}
		else  //使用原来的表,exit directly
			return 0;
	}
	int num = mysql_query(&mysql, "create table industry(industry_ID char(5) primary key,In_amount int,Out_amount int, Remain_amount int, Total_profit int) engine=innodb;");
	if (num == 0)
		printf("create table industry successully!\n\n");
	else
		printf("ERROR: create table industry\n\n");
	return 0;
}

int create_car_table()
{
	char yn[2];
	result = mysql_list_tables(&mysql, "car");//删除表
	unsigned int rows = mysql_num_rows(result);
	mysql_free_result(result);
	if (rows > 0)
	{
		printf("The car table already exists. Do you want to delete it?\n");
		printf("Delete the table?(y--yes,n--no):");
		scanf("%s", &yn);
		if (yn[0] == 'y' || yn[0] == 'Y')	//考虑大小写
		{
			if (!mysql_query(&mysql, "drop table car;"))
				printf("drop table car successfully!\n");
			else
				printf("error:drop table car failed.\n");
		}
		else  //使用原来的表,exit directly
			return 0;
	}
	int num = mysql_query(&mysql, "create table car(car_ID char(5) primary key,car_name char(20), car_profit int) engine=innodb;");
	if (num == 0)
		printf("create table car successully!\n\n");
	else
		printf("ERROR: create table car\n\n");
	return 0;
}

int create_possess_table()
{
	char yn[2];
	result = mysql_list_tables(&mysql, "possess");//删除表
	unsigned int rows = mysql_num_rows(result);
	mysql_free_result(result);
	if (rows > 0)
	{
		printf("The possess table already exists. Do you want to delete it?\n");
		printf("Delete the table?(y--yes,n--no):");
		scanf("%s", &yn);
		if (yn[0] == 'y' || yn[0] == 'Y')	//考虑大小写
		{
			if (!mysql_query(&mysql, "drop table possess;"))
				printf("drop table possess successfully!\n");
			else
				printf("error:drop table possess failed.\n");
		}
		else  //使用原来的表,exit directly
		{
			return 0;
		}
	}
	int num = mysql_query(&mysql, "create table possess(car_name char(20) primary key,car_amount int, industry_ID char(5), foreign key(industry_ID) references industry(industry_ID)) engine=innodb;");
	if (num == 0)
		printf("create table possess successully!\n\n");
	else
		printf("ERROR: create table possess\n\n");
	return 0;
}

int create_purchase_table()
{
	char yn[2];
	result = mysql_list_tables(&mysql, "purchase");//删除表
	unsigned int rows = mysql_num_rows(result);
	mysql_free_result(result);
	if (rows > 0)
	{
		printf("The purchase table already exists. Do you want to delete it?\n");
		printf("Delete the table?(y--yes,n--no):");
		scanf("%s", &yn);
		if (yn[0] == 'y' || yn[0] == 'Y')	//考虑大小写
		{
			if (!mysql_query(&mysql, "drop table purchase;"))
				printf("drop table purchase successfully!\n");
			else
				printf("error:drop table purchase failed.\n");
		}
		else  //使用原来的表,exit directly
			return 0;
	}
	int num = mysql_query(&mysql, "create table purchase(car_name char(20),customer_ID char(5) ,industry_ID char(5), amount int, foreign key(industry_ID) references industry(industry_ID),foreign key(customer_ID) references customer(customer_ID)) engine=innodb;");
	if (num == 0)
		printf("create table purchase successully!\n\n");
	else
		printf("ERROR: create table purchase\n\n");
	return 0;
}

int insert_rows_into_customer_table()
{
	while (1)
	{
		char customer_ID[5] = "0";
		char customer_name[20] = "xx";
		char customer_sex[4] = "男";
		char customer_phone[15] = "00";

		char yn[2];	//用来判断是否继续插入
		char strquery[200] = "insert into customer(customer_ID,customer_name,customer_sex,customer_phone) values('";
		//insert customer_ID
		printf("Please input customer_ID:");
		scanf("%s", customer_ID);
		strcat(strquery, customer_ID);
		strcat(strquery, "','");
		//insert customer_name
		printf("Please input customer_name:");	//注意！！用scanf不能读空格！所以只能打下划线连接课程名。
		scanf("%s", customer_name);
		strcat(strquery, customer_name);
		strcat(strquery, "','");
		//insert customer_sex
		printf("Please input customer_sex:");	//注意！！用scanf不能读空格！所以只能打下划线连接课程名。
		scanf("%s", customer_sex);
		strcat(strquery, customer_sex);
		strcat(strquery, "','");
		//insert customer_phone
		printf("Please input customer_phone:");
		scanf("%s", customer_phone);
		strcat(strquery, customer_phone);
		strcat(strquery, "');");	//输到sql中以分号结尾
		//printf("%s\n", strquery);
		//check whether execute successfully
		if (mysql_query(&mysql, strquery) != 0)
		{
			printf("error:insert executes failed\n");
			printf("%s\n", mysql_error(&mysql));
		}
		//判断是否需要继续插入记录
		printf("\nInsert again?(y/n):");
		scanf("%s", &yn);
		printf("\n");
		if (yn[0] == 'y' || yn[0] == 'Y')
			continue;
		else
			break;
	}
	return 0;
}

int insert_rows_into_industry_table()
{
	while (1)
	{
		char industry_ID[5] = "0";
		char In_amount[5] = "0";
		char Out_amount[5] = "0";
		char Remain_amount[5] = "0";
		char Total_profit[5] = "0";

		char yn[2];	//用来判断是否继续插入
		char strquery[200] = "insert into industry(industry_ID, In_amount, Out_amount, Remain_amount, Total_profit) values('";
		//insert industry_ID
		printf("Please input industry_ID:");
		scanf("%s", industry_ID);
		strcat(strquery, industry_ID);
		strcat(strquery, "','");
		//insert In_amount
		printf("Please input In_amount:");	//注意！！用scanf不能读空格！所以只能打下划线连接课程名。
		scanf("%s", In_amount);
		strcat(strquery, In_amount);
		strcat(strquery, "','");
		//insert Out_amount
		printf("Please input Out_amount:");	//注意！！用scanf不能读空格！所以只能打下划线连接课程名。
		scanf("%s", Out_amount);
		strcat(strquery, Out_amount);
		strcat(strquery, "','");
		//insert Remain_amount
		printf("Please input Remain_amount:");
		scanf("%s", Remain_amount);
		strcat(strquery, Remain_amount);
		strcat(strquery, "','");
		//insert Remain_amount
		printf("Please input Total_profit:");
		scanf("%s", Total_profit);
		strcat(strquery, Total_profit);
		strcat(strquery, "');");	//输到sql中以分号结尾
		//printf("%s\n", strquery);
		//check whether execute successfully
		if (mysql_query(&mysql, strquery) != 0)
		{
			printf("error:insert executes failed\n");
			printf("%s\n", mysql_error(&mysql));
		}
		//判断是否需要继续插入记录
		printf("### Insert again?(y/n):");
		scanf("%s", &yn);
		printf("\n");
		if (yn[0] == 'y' || yn[0] == 'Y')
			continue;
		else
			break;
	}
	return 0;
}

int insert_rows_into_car_table(char* car_name=NULL)
{
	char car_ID[5] = "0";
	char car_profit[6] = "0";

	char strquery[200] = "insert into car(car_ID, car_name, car_profit) values('";
	//insert car_ID
	printf("Please input car_ID:");
	scanf("%s", car_ID);
	strcat(strquery, car_ID);
	strcat(strquery, "','");
	//concatenate car_name
	strcat(strquery, car_name);
	strcat(strquery, "','");
	//insert car_profit
	printf("Please input car_profit:");	//注意！！用scanf不能读空格！所以只能打下划线连接课程名。
	scanf("%s", car_profit);
	strcat(strquery, car_profit);
	strcat(strquery, "');");	//输到sql中以分号结尾
	printf("\n");
	//printf("%s\n", strquery);
	//check whether execute successfully
	if (mysql_query(&mysql, strquery) != 0)
	{
		printf("error:insert executes failed\n");
		printf("%s\n", mysql_error(&mysql));
	}
	return 0;
}

int select_car_ID_with_name(char* car_name, char* ID)
{
	char strquery[200] = "select car_ID from car where car_name='";
	strcat(strquery, car_name);
	strcat(strquery, "'");
	mysql_query(&mysql, strquery);
	result = mysql_store_result(&mysql);
	MYSQL_ROW row;
	row = mysql_fetch_row(result);
	if (row == NULL)
	{
		printf("当前厂商没有%s车型。\n\n", car_name);
		return -1;
	}
	printf("当前厂商%s的%s车辆的ID有：", ID, car_name);
	while (row!=NULL)
	{
		printf("%s\n", row[0]);
		row = mysql_fetch_row(result);
	}
	if (mysql_errno(&mysql))
	{
		fprintf(stderr, "Error:%s\n", mysql_error(&mysql));
		return 0;
	}
	return 0;
}

int update_possess_table(char* car_name, char* number, char* industry_ID, bool exist,bool purchase)
{
	if (exist && !purchase)//进货：该车原存在于厂商中，更新数量
	{
		char strquery[200] = "update possess set car_amount=car_amount+";
		strcat(strquery, number);
		strcat(strquery, " where car_name='");
		strcat(strquery, car_name);
		strcat(strquery, "';");
		//printf("%s\n", strquery);
		if (mysql_query(&mysql, strquery) != 0)
		{
			printf("error:update executes failed\n");
			printf("%s\n", mysql_error(&mysql));
		}		
	}
	else if (exist && purchase)//出货：该车原存在于厂商中，减少数量
	{
		//判断出货后，此车型数量是否为0
		char strquery[200] = "select car_amount from possess where car_name='";
		strcat(strquery, car_name);
		strcat(strquery, "'");
		mysql_query(&mysql, strquery);
		result = mysql_store_result(&mysql);
		MYSQL_ROW row;
		row = mysql_fetch_row(result);
		//1：数量为0，需删除possess中对应的该行
		if (strcmp(row[0],number)==0)
		{
			char strquery1[200] = "delete from possess where car_name='";
			strcat(strquery1, car_name);
			strcat(strquery1, "'");
			if (mysql_query(&mysql, strquery1)!=0)
				printf("possess表项删除失败！\n");
		}
		//2：数量不为0，更新possess表，减少数量
		else
		{
			char strquery1[200] = "update possess set car_amount=car_amount-";
			strcat(strquery1, number);
			strcat(strquery1, " where car_name='");
			strcat(strquery1, car_name);
			strcat(strquery1, "';");
			//printf("%s\n", strquery1);
			if (mysql_query(&mysql, strquery1) != 0)
			{
				printf("error:update possess table executes failed\n");
				printf("%s\n", mysql_error(&mysql));
			}		
		}
		
	}
	else	//该车原不存在于厂商，插入
	{
		char strquery[200] = "insert into possess(car_name,car_amount, industry_ID) values('";
		strcat(strquery, car_name);
		strcat(strquery, "','");
		strcat(strquery, number);
		strcat(strquery, "','");
		strcat(strquery, industry_ID);
		strcat(strquery, "');");	//输到sql中以分号结尾
		//printf("%s\n", strquery);
		//check whether execute successfully
		if (mysql_query(&mysql, strquery) != 0)
		{
			printf("error:insert executes failed\n");
			printf("%s\n", mysql_error(&mysql));
		}
	}
	return 0;
}

int update_industry_table(char* industry_ID, char* number, bool purchase, char*profit=NULL)
{
	if (!purchase)
	{
		char strquery[200] = "update industry set In_amount=In_amount+";
		strcat(strquery, number);
		strcat(strquery, " where industry_ID='");
		strcat(strquery, industry_ID);
		strcat(strquery, "';");
		//printf("%s\n", strquery);
		if (mysql_query(&mysql, strquery) != 0)
		{
			printf("error:update executes failed\n");
			printf("%s\n", mysql_error(&mysql));
		}

		char strquery1[200] = "update industry set Remain_amount=Remain_amount+";
		strcat(strquery1, number);
		strcat(strquery1, " where industry_ID='");
		strcat(strquery1, industry_ID);
		strcat(strquery1, "';");
		//printf("%s\n", strquery1);
		if (mysql_query(&mysql, strquery1) != 0)
		{
			printf("error:update executes failed\n");
			printf("%s\n", mysql_error(&mysql));
		}
	}
	else//买车
	{
		char strquery[200] = "update industry set Out_amount=Out_amount+";
		strcat(strquery, number);
		strcat(strquery, " where industry_ID='");
		strcat(strquery, industry_ID);
		strcat(strquery, "';");
		//printf("%s\n", strquery);
		if (mysql_query(&mysql, strquery) != 0)
		{
			printf("error:update executes failed\n");
			printf("%s\n", mysql_error(&mysql));
		}

		char strquery1[200] = "update industry set Remain_amount=Remain_amount-";
		strcat(strquery1, number);
		strcat(strquery1, " where industry_ID='");
		strcat(strquery1, industry_ID);
		strcat(strquery1, "';");
		//printf("%s\n", strquery1);
		if (mysql_query(&mysql, strquery1) != 0)
		{
			printf("error:update executes failed\n");
			printf("%s\n", mysql_error(&mysql));
		}
		
		char strquery2[200] = "update industry set Total_profit=Total_profit+";
		strcat(strquery2, profit);
		strcat(strquery2, " where industry_ID='");
		strcat(strquery2, industry_ID);
		strcat(strquery2, "';");
		//printf("%s\n", strquery2);
		if (mysql_query(&mysql, strquery2) != 0)
		{
			printf("error:update executes failed\n");
			printf("%s\n", mysql_error(&mysql));
		}
	}
	return 0;
}

int delete_car_table_ID(char* name, char*& profit)
{
	char strquery[200] = "select car_ID,car_profit from car where car_name='";
	strcat(strquery, name);
	strcat(strquery, "'");
	mysql_query(&mysql, strquery);
	result = mysql_store_result(&mysql);
	MYSQL_ROW row;
	char ID[5];
	
	if((row = mysql_fetch_row(result)) != NULL)
	{
		strcpy(ID, row[0]);
		strcpy(profit, row[1]);
	}
	char strquery1[200] = "delete from car where car_ID='";
	strcat(strquery1, ID);
	strcat(strquery1, "'");
	if (mysql_query(&mysql, strquery1)!=0)
	{
		printf("删除失败！\n");
	}
	return 0;
}

int select_purchase_table_with_car_name_and_customer_ID(char* ID, char* car_name)
{
	char strquery[200] = "select * from purchase where customer_ID='";
	strcat(strquery, ID);
	strcat(strquery, "' and car_name='");
	strcat(strquery, car_name);
	strcat(strquery, "';");
	mysql_query(&mysql, strquery);
	result = mysql_store_result(&mysql);
	MYSQL_ROW row;
	row = mysql_fetch_row(result);
	if (row == NULL)
	{
		//printf("当前客户没有购买过%s车型。\n\n", car_name);
		return -1;
	}
	else
		return 0;
}

int update_purchase_table(char* ID, char* industry_ID, char* car_name, char* number)
{
	int exist = select_purchase_table_with_car_name_and_customer_ID(ID, car_name);
	if (exist == -1)
	{
		char strquery[200] = "insert into purchase(car_name, customer_ID, industry_ID, amount) values('";
		strcat(strquery, car_name);
		strcat(strquery, "','");
		strcat(strquery, ID);
		strcat(strquery, "','");
		strcat(strquery, industry_ID);
		strcat(strquery, "',");
		strcat(strquery, number);
		strcat(strquery, ");");	//输到sql中以分号结尾
		//printf("%s\n", strquery);
		if (mysql_query(&mysql, strquery) != 0)
		{
			printf("error:insert executes failed\n");
			printf("%s\n", mysql_error(&mysql));
		}

	}
	else
	{
		char strquery[200] = "update purchase set amount=amount+";
		strcat(strquery, number);
		strcat(strquery, " where customer_ID='");
		strcat(strquery, ID);
		strcat(strquery, "' and car_name='");
		strcat(strquery, car_name);
		strcat(strquery,"'");
		//printf("%s\n", strquery);
		if (mysql_query(&mysql, strquery) != 0)
		{
			printf("error:update executes failed\n");
			printf("%s\n", mysql_error(&mysql));
		}
	}
	return 0;
}

int import_car(char* ID)
{
	char yn[2];	//用来判断是否继续插入
	while (1)
	{
		char car_name[21];
		printf("请输入要买的车型号：");
		scanf("%s", &car_name);
		int temp = select_car_ID_with_name(car_name, ID);
		bool exist = temp == -1 ? false : true;
		printf("请输入你要进货的数量：");
		char number[5];
		scanf("%s", &number);
		int number1 = number[0] - '0';
		while (number1--)
		{
			insert_rows_into_car_table(car_name);//更新车辆表
		}
		update_possess_table(car_name, number, ID, exist, false);		//更新拥有表
		update_industry_table(ID, number, false);//更新厂商表
	
		//判断是否需要继续插入记录
		printf("### Import car again?(y/n):");
		scanf("%s", &yn);
		printf("\n");
		if (yn[0] == 'y' || yn[0] == 'Y')
			continue;
		else
			break;
	}
	return 0;
}

int purchase_car(char* ID) 
{
	char yn[2];
	printf("是否需要购买车辆？（请输入y/n）");
	scanf("%s", &yn);
	if (yn[0] == 'n' || yn[0] == 'N')
	{
		return 0;
	}
	else
	{
		printf("您有以下厂商可供选择：\n");
		char strquery[200] = "select industry_ID from industry";
		mysql_query(&mysql, strquery);
		result = mysql_store_result(&mysql);
		MYSQL_ROW row;
		row = mysql_fetch_row(result);
		if (row == NULL)
		{
			printf("当前系统中不存在厂商。\n\n");
			return -1;
		}
		while (row != NULL)
		{
			printf("%s\t", row[0]);
			row = mysql_fetch_row(result);
		}
		if (mysql_errno(&mysql))
		{
			fprintf(stderr, "Error:%s\n", mysql_error(&mysql));
			return 0;
		}
		printf("\n你想从哪个厂商购买车辆？请输入名称：");
		char industry_ID[5];
		scanf("%s", industry_ID);
		printf("\n");
		char strquery1[200] = "select car_name,car_amount from possess where industry_ID='";
		strcat(strquery1, industry_ID);
		strcat(strquery1, "'");
		mysql_query(&mysql, strquery1);
		result = mysql_store_result(&mysql);

		row = mysql_fetch_row(result);
		if (row == NULL)
		{
			printf("当前厂商没有车辆库存。\n\n");
			return -1;
		}
		printf("当前厂商%s的车辆有：\n", industry_ID);
		while (row != NULL)
		{
			printf("%-12s%s\n", row[0],row[1]);
			row = mysql_fetch_row(result);
		}
		printf("请输入您想购买的车辆名称及数量：（以空格分隔）");
		char number[3];
		char name[10];
		scanf("%s", name);
		scanf("%s", number);
		int number1 = number[0] - '0';
		//更新possess表
		update_possess_table(name,number,industry_ID,true,true);
		char* profit = (char*)malloc(sizeof(char) * 6);
		char temp_str[3] = "1";
		while (number1--)
		{
			//删除car表中含有该车辆名称的第一行
			delete_car_table_ID(name, profit);
			//更新industry表
			update_industry_table(industry_ID, temp_str, true, profit);	
		}
		free(profit);
		//更新purchase表，直接插入一行
		update_purchase_table(ID, industry_ID, name, number);
		
	}
	return 0;
}

int select_industry_info(char* ID)
{
	char strquery[200] = "select Remain_amount,Out_amount, Total_profit from industry where industry_ID='";
	strcat(strquery, ID);
	strcat(strquery, "'");
	mysql_query(&mysql, strquery);
	result = mysql_store_result(&mysql);
	MYSQL_ROW row;
	while ((row = mysql_fetch_row(result)) != NULL)
	{
		printf("当前厂商%s的车辆总数为%s\n", ID, row[0]);
		printf("当前厂商%s的总销量为%s\n", ID, row[1]);
		printf("当前厂商%s的总利润为%s\n\n", ID, row[2]);
	}
	if (mysql_errno(&mysql))
	{
		fprintf(stderr, "Error:%s\n", mysql_error(&mysql));
		return 0;
	}
	return 0;
}

int select_car_name_and_number(char* ID)
{
	char strquery[200] = "select car_name,car_amount from possess where industry_ID='";
	strcat(strquery, ID);
	strcat(strquery, "'");
	mysql_query(&mysql, strquery);
	result = mysql_store_result(&mysql);
	MYSQL_ROW row;
	row = mysql_fetch_row(result);
	if (row == NULL)
		printf("当前厂商%s仓库中没有车辆。\n\n", ID);
	else
	{
		//int num_fields = mysql_field_count(&mysql);
		printf("当前厂商%s仓库库存有的车辆品牌及数量为：\n",ID);
		while (row != NULL)
		{
			printf("%-12s%s\n", row[0], row[1]);
			row = mysql_fetch_row(result);
		}
		printf("\n");
	}
	if (mysql_errno(&mysql))
		fprintf(stderr, "Error:%s\n", mysql_error(&mysql));
	return 0;
}

int select_customer_ID(char* ID)
{
	char strquery[200] = "select customer_name,customer_sex,customer_phone from customer where customer_ID='";
	strcat(strquery, ID);
	strcat(strquery, "'");
	mysql_query(&mysql, strquery);
	result = mysql_store_result(&mysql);
	MYSQL_ROW row;
	row = mysql_fetch_row(result);
	if (row == NULL)
		printf("当前系统中没有%s客户的信息\n\n", ID);
	else
	{
		//int num_fields = mysql_field_count(&mysql);
		printf("当前%s客户的基本信息为：\n",ID);
		printf("客户ID：%s\n", ID);
		while (row != NULL)
		{
			printf("客户姓名：%s\n", row[0]);
			printf("客户性别：%s\n", row[1]);
			printf("客户电话：%s\n", row[2]);
			row = mysql_fetch_row(result);
		}
		printf("\n");
	}
	if (mysql_errno(&mysql))
		fprintf(stderr, "Error:%s\n", mysql_error(&mysql));
	return 0;
}

int select_purchase_info(char* ID)
{
	char strquery[200] = "select car_name, industry_ID, amount from purchase where customer_ID='";
	strcat(strquery, ID);
	strcat(strquery, "';");
	mysql_query(&mysql, strquery);
	result = mysql_store_result(&mysql);
	MYSQL_ROW row;
	row = mysql_fetch_row(result);
	if (row == NULL)
		printf("当前系统中没有%s客户的购买信息\n\n", ID);
	else
	{

		printf("当前%s客户的购买信息为：\n", ID);
		while (row != NULL)
		{
			printf("车辆型号：%-12s\t厂商：%-5s\t数量：%-5s\n", row[0], row[1], row[2]);
			row = mysql_fetch_row(result);
		}
		printf("\n");
	}
	if (mysql_errno(&mysql))
		fprintf(stderr, "Error:%s\n", mysql_error(&mysql));
	return 0;
}


int main(int argc, char** argv, char** envp)
{
	char role[2];
	char func[2];//储存要执行的操作的变量
	mysql_init(&mysql);	//初始化一个MYSQL结构
	//mysql_real_connect()连接到MYSQL数据库服务器。"localhost"为服务器名，
	//"root"为连接用户名，123456为密码，car为数据库名，3306位连接端口号
	mysql_options(&mysql, MYSQL_SET_CHARSET_NAME, "gbk");//插入这句话可以使得sql输入中文。
	if (mysql_real_connect(&mysql, "localhost", "root", "123456", "car", 3306, 0, 0))
	{
		printf("Sample Embedded SQL for C application\n\n");
		while(1)
		{	
			system("cls");
			printf("选择一个角色登录系统\n\n");
			printf("1---管理员（可以新增厂商和客户信息）\n");
			printf("2---厂商（可以进货已经存在的车辆）\n");
			printf("3---客户（可以向系统中存在的厂商购买已有车辆）\n\n");
			printf("请输入你选择的角色：");
			scanf("%s", &role);
			printf("\n");
			if (role[0] == '1') //管理员
			{
				system("cls");
				while (1) {
					printf("######################################\n");
					printf("# 0--exit.                           #\n");
					printf("# 1--创建客户表  2--添加客户信息     #\n");
					printf("# 3--创建厂商表  4--添加厂商信息     #\n");
					printf("# 5--创建车辆表  6--创建拥有表       #\n");
					printf("# 7--创建购买表                      #\n");
					printf("######################################\n");
					printf("请选择你需要的功能:");
					scanf("%s", &func);
					printf("\n\n");
					if (func[0] == '0')
						break;
					else if (func[0] == '1')
						create_customer_table();
					else if (func[0] == '2')
						insert_rows_into_customer_table();
					else if (func[0] == '3')
						create_industry_table();
					else if (func[0] == '4')
						insert_rows_into_industry_table();
					else if (func[0] == '5')
						create_car_table();
					else if (func[0] == '6')
						create_possess_table();
					else if (func[0] == '7')
						create_purchase_table();
					printf("\n");
				}
			}
			else if (role[0] == '2') 
			{
				system("cls");
				char ID[5];
				printf("请输入ID信息：");
				scanf("%s", &ID);
				system("cls");
				while (1) 
				{
					printf("#############################################\n");
					printf("# 0--exit.        1--统计厂商基本信息       #\n");
					printf("# 2--进货         3--统计现有车辆品牌及数量 #\n");
					printf("#############################################\n");
					printf("请选择你需要的功能:");
					scanf("%s", &func);
					printf("\n");
					if (func[0] == '0')
						break;
					else if (func[0] == '1')
						select_industry_info(ID);
					else if (func[0] == '2')
						import_car(ID);
					else if (func[0] == '3')
						select_car_name_and_number(ID);
					printf("\n");
				}
			}
			else if (role[0] == '3')
			{
				system("cls");
				char ID[5];
				printf("请输入ID信息：");
				scanf("%s", &ID);
				while (1)
				{
					printf("########################################\n");
					printf("# 0--exit.        1--输出客户信息      #\n");
					printf("# 2--购买车辆     3--统计购买车辆信息  #\n");
					printf("########################################\n");
					printf("请选择你需要的功能:");
					scanf("%s", &func);
					printf("\n");
					if (func[0] == '0')
						break;
					else if (func[0] == '1')
						select_customer_ID(ID);
					else if (func[0] == '2')
						purchase_car(ID);
					else if (func[0] == '3')
						select_purchase_info(ID);
					printf("\n");
				}
			}

		}
	}
	else
	{
		printf("数据库不存在！\n");
	}
	mysql_close(&mysql);//访问完毕，关闭数据库mysql
	result = mysql_store_result(&mysql);
	mysql_free_result(result);
	system("pause");
	return 0;
}