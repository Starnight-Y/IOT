extern int user_num;
extern int cou_Count;
//�������Ա����
int cou_search(int cou_num){
    int i;
    for(i=0;i<cou_Count;i++)
        if(c[i].num==cou_num)  return i;
    return NO_FOUND;
}
//������֤
int cou_land(){
    int i=1,j,temp;
    char user_pwd[15];
    char pwd;
    do{
        printf("\n�����������û�����");
        scanf("%d",&user_num);
        printf("\n�������������룺");
        system("stty -echo");
        pwd=getchar();
        scanf("%s",&pwd);
        system("stty echo");
        if((temp=cou_search(user_num))==NO_FOUND){
            printf("\n�û�������");
        }
        else{
            if(c[temp].num==user_num&&(strcmp(c[temp].password,&pwd)==0))
                return YES;
            else
                printf("\n�������");
        }
        printf("���������룡\n");
        i++;
        printf("---------------------------------------------\n");
        }while(i<3);
        return NO;
}
//���Ա�������˵� 
int cou_menu(){
    int choice=-1;
    printf("\n\n");
    printf("\t\t ----------------------------------------------------\n");
    printf("\t\t|                 ���Ա��Ϣ����ϵͳ                 |\n");
    printf("\t\t|----------------------------------------------------|\n");
    printf("\t\t|           [1]----------------��ѯ������Ϣ          |\n");
    printf("\t\t|           [2]----------------�޸ĸ�����Ϣ          |\n");
    printf("\t\t|           [3]----------------��ѯ�����Ϣ          |\n");
    printf("\t\t|           [4]----------------���������Ϣ          |\n");
    printf("\t\t|           [5]----------------��ݽ�������Ա        |\n");
    printf("\t\t|                                                    |\n");
    printf("\t\t|           [0]----------------�˳�ϵͳ              |\n");
    printf("\t\t ----------------------------------------------------\n");
    printf("����������ѡ��");
    scanf("%d",&choice);
    return choice;
} 
//���Ա���ܿ��ƺ���
void courier(){
    int choice,temp,o=0,p=0;
    int putpac;
    system("./clear.sh");
    do{
        choice=cou_menu();
        system("./clear.sh");
        switch(choice){
            case 1:
                temp=cou_search(user_num);
                printf("�˺ţ�");
                printf("%d\n",c[temp].num);
                printf("������");
                printf("%s\n",c[temp].name);
                printf("�ֻ��ţ�");
                printf("%s\n",c[temp].phone);
                printf("��¼���룺");
                printf("%s\n",c[temp].password);
                break;
            case 2:
                cou_modify();
                system("./clear.sh");
                continue;
            case 3:
                for(int i=0;i<package_Count;i++){
                    if(strcmp(pac[i].cou_phone,c[temp].phone)==0){
                        printf("��ݵ��ţ�%d\t",pac[i].num);
                        printf("�ռ��ˣ�%s\t",pac[i].name);
                        printf("�ռ����ֻ���%s\t",pac[i].stu_phone);
                        printf("���Ա�ֻ���%s\t",pac[i].cou_phone);
                        printf("���״̬��%s\n",pac[i].state);
                        o=1;
                    }                  
                }
                if(o==0){
                    printf("�޽����");
                }
                break;
            case 4:
                add_package();
                break;
            case 5:
                printf("\n\n\n\n������Ҫ�ύ�Ŀ�ݵ��ţ�");
                scanf("%d",&putpac);
                for(int i=0;i<package_Count;i++){
                   if((pac[i].num==putpac)&&strcmp(pac[i].cou_phone,c[temp].phone)==0&&strcmp(pac[i].state,"delivery")==0){
                        strcpy(pac[i].state,"arrival");
                        printf("�ύ�ɹ���");
                        p=1;
                    }
                }
                if(p==0){
                    printf("�ύʧ�ܣ�"); 
                }
                break;
            case 0:
                save_courier_information((char*)"courier.txt");
                save_package_information((char*)"package.txt");
                exit_system();
                break;
            default:
                printf("\n�Բ�����ѡ�����\n");
                break;    
        } 
        printf("\n\n\n\n��Enter�����ء���");
        getchar();
        if(getchar())
            system("./clear.sh");
    }while(1);
}
//���Ա�޸ĸ�����Ϣ 
void cou_modify(){
    int temp;
    int choice;
    temp=cou_search(user_num);
    system("./clear.sh");
    do{
        printf("\n\n");
        printf("\t\t ----------------------------------------------------\n");
        printf("\t\t|                ��ѡ����Ҫ�޸ĵ���Ϣ                |\n");
        printf("\t\t|----------------------------------------------------|\n");
        printf("\t\t|                                                    |\n");
        printf("\t\t|           ����                     �밴 1          |\n");
        printf("\t\t|           �ֻ�����                 �밴 2          |\n");
        printf("\t\t|           ��¼����                 �밴 3          |\n");
        printf("\t\t|                                                    |\n");
        printf("\t\t|           ȡ��                     �밴 0          |\n");
        printf("\t\t|                                                    |\n");
        printf("\t\t ----------------------------------------------------\n");
        printf("��ѡ��");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("��������������");
                scanf("%s",c[temp].name);
                break;
            case 2:
                printf("���������ֻ����룺");
                scanf("%s",c[temp].phone);
                break;
            case 3:
                printf("�����������룺");
                scanf("%s",c[temp].password);
                break;
            case 0:
                return;
            default:
                printf("\n��Чѡ�");
                continue; 
            }
            printf("\n\n\n\n��Enter�����ء���");
            getchar();
            if(getchar()) system("./clear.sh");      
    }while(choice!=0);
} 
