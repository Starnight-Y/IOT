#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "termios.h"
#include "unistd.h"
#include "macro_file.h"                        //�궨���ļ� 
#include "struct_file.h"                       //�ṹ���ļ� 
#include "function_declare_file.h"             //���������ļ� 
#include "student_file.c"                      //ѧ�������ļ� 
#include "courier_file.c"                      //���Ա�����ļ� 
#include "administrator_file.c"                //����Ա�����ļ�
//ȫ�ֱ���
int stu_Count;                                 //ѧ������ 
int package_Count;                             //������� 
int user_num;                                  //�˺� 
int cou_Count;                                 //���Ա���� 
//������
int main(){
    int temp,choice,t=-1;
    system("./judgeS.sh");                     //�����ǰû��student.txt�ļ����򴴽�һ�� 
    system("./judgeC.sh");                     //�����ǰû��courier.txt�ļ����򴴽�һ��
    system("./judgeP.sh");                     //�����ǰû��package.txt�ļ����򴴽�һ��
    system("./clear.sh");                      //���� 
    welcome();                                 //��ӭ����
    choice=user_type();                        //�û�ѡ�����
    if(choice!=0){
        Load_package_information((char*)"package.txt");
        Load_student_information((char*)"student.txt");
        Load_courier_information((char*)"courier.txt");
        getchar();
        if(getchar()) system("./clear.sh");     //���� 
            if(choice==1){
                t=regs();                       //��¼ע����� 
                if(t==1){
                    regs_student();             //ѧ��ע��
                    temp=land(choice); 
                }
                else if(t==0){
                    exit_system();              //�˳�ϵͳ 
                }
                else if(t==2){
                    temp=land(choice);          //ѧ����¼ 
                }
            }
            else if(choice==2){
                temp=land(choice);              //����Ա��¼ 
            }
            else if(choice==3){
                t=regs();
                if(t==1){
                    regs_courier();             //���Աע��
                    temp=land(choice); 
                }
                else if(t==0){
                    exit_system();              //�˳�ϵͳ 
                }
                else if(t==2){
                    temp=land(choice);          //���Ա��¼ 
                }
            }
            if(temp==YES){
                system("./clear.sh");
                switch(choice){
                case 1:
                    student();                  //ѧ������ 
                    break;
                case 2:
                    administrator();            //����Ա���� 
                    break;
                case 3:
                    courier();                  //���Ա���� 
                    break;
                }
            }
            else
                printf("\n�Բ������ĵ�¼���������꣡\n��ӭ�´ε�¼��\n");
    }
    else
        printf("\nϵͳ���˳�����ӭ�´ε�¼��\n"); 
    return 0;
}
//��ӭ����
void welcome(){
    printf("\n\n");
    printf("\t\t ----------------------------------------------------\n");
    printf("\t\t|                                                    |\n");
    printf("\t\t|                                                    |\n");
    printf("\t\t|                                                    |\n");
    printf("\t\t|                                                    |\n");
    printf("\t\t|             ��ӭʹ��֮��ѧԺ������վ               |\n");
    printf("\t\t|                                                    |\n");
    printf("\t\t|                                                    |\n");
    printf("\t\t|                                                    |\n");
    printf("\t\t|                                                    |\n");
    printf("\t\t ----------------------------------------------------\n");
    printf("\n\n\n\n��Enter�����ء���");
    if(getchar())
        system("./clear.sh");
}
//ѡ���û����ͽ���
int user_type(){
    int choice;
    choice=-1;
    system("./clear.sh");
    printf("\n\n");
    printf("\t\t ----------------------------------------------------\n");
    printf("\t\t|                     �û�����                       |\n");
    printf("\t\t|----------------------------------------------------|\n");
    printf("\t\t|                                                    |\n");
    printf("\t\t|           [1]----------------ѧ��                  |\n");
    printf("\t\t|           [2]----------------����Ա                |\n");
    printf("\t\t|           [3]----------------���Ա                |\n");
    printf("\t\t|                                                    |\n");
    printf("\t\t|           [0]----------------�˳�ϵͳ              |\n");
    printf("\t\t|                                                    |\n");
    printf("\t\t ----------------------------------------------------\n");
    printf("\n\n\n����������ѡ��");
    scanf("%d",&choice);
    return choice; 
} 
//ϵͳ�˳�����
void exit_system(){
    system("./clear.sh");
    printf("\n\n");
    printf("\t\t ----------------------------------------------------\n");
    printf("\t\t|                                                    |\n");
    printf("\t\t|                                                    |\n");
    printf("\t\t|                                                    |\n");
    printf("\t\t|                                                    |\n");
    printf("\t\t|            ��л����ʹ�ã���ӭ�´ε�¼��:)          |\n");
    printf("\t\t|                                                    |\n");
    printf("\t\t|                                                    |\n");
    printf("\t\t|                                                    |\n");
    printf("\t\t|                                                    |\n");
    printf("\t\t ----------------------------------------------------\n");
    exit(0);
}
//ע�����
int regs()
{
    int ch;
    ch = -1;
    system("./clear.sh");
	printf("\n\n");
    printf("\t\t ----------------------------------------------------\n");
    printf("\t\t|                                                    |\n");
    printf("\t\t|                                                    |\n");
    printf("\t\t|            [1]----------------���û�               |\n");
    printf("\t\t|            [2]----------------���û�               |\n");
    printf("\t\t|                                                    |\n");
    printf("\t\t|            [0]----------------�˳�ϵͳ             |\n");
    printf("\t\t|                                                    |\n");
    printf("\t\t|                                                    |\n");
    printf("\t\t|                                                    |\n");
    printf("\t\t ----------------------------------------------------\n");
    printf("\n\n\n����������ѡ��");
    scanf("%d", &ch);
    if(getchar()) 
        system("./clear.sh"); 
    return ch;
} 
//���Ƶ�¼����
int land(int user_type){
    int temp;
    switch(user_type){
        case 1:
            temp=stu_land();                    //ѧ��                              
            break;
        case 2:
            temp=admin_land();                  //����Ա��֤ 
            break;
        case 3:
            temp=cou_land();                    //���Ա��֤ 
            break;
        default:
            printf("\n�Բ�����ѡ�����\n");
            break;
    }
    return temp;
} 
//linux�ж�ȡ�����ַ����ò����� 
int getch(){
    struct termios oldt,newt;
    int ch;
    tcgetattr(STDIN_FILENO,&oldt);
    newt=oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO,TCSANOW,&newt);
    ch=getchar();
    tcsetattr(STDIN_FILENO,TCSANOW,&oldt);
    return ch;
}
