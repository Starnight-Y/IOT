extern int user_num;
extern int stu_Count;
extern int package_Count;
//����ѧ������
int stu_search(int stu_num){
    int i;
    for(i=0;i<stu_Count;i++)
        if(s[i].num==stu_num) return i;
    return NO_FOUND;
}
//������֤
int stu_land(){
    int i=1,j,temp;
    char user_pwd[15];
    char pwd;
    do{
        printf("\n�����������û�����");
        scanf("%d",&user_num);
        printf("\n�������������룺");
        system("stty -echo");                                                          //������ܣ���������������� 
        pwd=getchar();
        scanf("%s",&pwd);
        system("stty echo");                                                           //������ܣ����������������
        if((temp=stu_search(user_num))==NO_FOUND){
            printf("\n�û�������");
        }
        else{
            if(s[temp].num==user_num&&(strcmp(s[temp].password,&pwd)==0))
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
//ѧ���������˵�
int stu_menu(){
    int choice=-1;
    printf("\n\n");
    printf("\t\t ----------------------------------------------------\n");
    printf("\t\t|                 ѧ����Ϣ����ϵͳ                   |\n");
    printf("\t\t|----------------------------------------------------|\n");
    printf("\t\t|           [1]----------------��ѯ������Ϣ          |\n");
    printf("\t\t|           [2]----------------�޸ĸ�����Ϣ          |\n");
    printf("\t\t|           [3]----------------��ѯ�����Ϣ          |\n");
    printf("\t\t|           [4]----------------ȡ��                  |\n");
    printf("\t\t|                                                    |\n");
    printf("\t\t|           [0]----------------�˳�ϵͳ              |\n");
    printf("\t\t|                                                    |\n");
    printf("\t\t ----------------------------------------------------\n");
    printf("����������ѡ��");
    scanf("%d",&choice);
    return choice;
}
//ѧ�����ܿ��ƺ��� 
void student(){
    int choice,temp;
    int pacnum,o=0,p=0;
    char location[20],code[20];
    system("./clear.sh");
    do{
        choice=stu_menu();
        system("./clear.sh");
        switch(choice){
            case 1:                                                                  //��ѯѧ��������Ϣ 
                temp=stu_search(user_num);
                printf("�˺ţ�");
                printf("%d\n",s[temp].num);
                printf("������");
                printf("%s\n",s[temp].name);
                printf("�ֻ��ţ�");
                printf("%s\n",s[temp].phone);
                printf("��¼���룺");
                printf("%s\n",s[temp].password);
                break;
            case 2:                                                                  //�޸�ѧ��������Ϣ 
                stu_modify();
                system("./clear.sh");
                continue;
            case 3:                                                                  //��ѯ��ѧ�������Ŀ����Ϣ 
                for(int i=0;i<package_Count;i++){
                    if(strcmp(pac[i].stu_phone,s[temp].phone)==0){
                        printf("��ݵ��ţ�%d\t",pac[i].num);
                        printf("�ռ��ˣ�%s\t",pac[i].name);
                        printf("�ռ����ֻ���%s\t",pac[i].stu_phone);
                        printf("���Ա�ֻ���%s\t",pac[i].cou_phone);
                        printf("���ڿ�ݹ�λ�ã�%s\t",pac[i].location);
                        printf("���״̬��%s\t",pac[i].state);
                        printf("ȡ���룺%s\n",pac[i].code);
                        o=1;
                    }
                 }
                 if(o==0){
                     printf("no result!");
                 }
                break;
            case 4:                                                                   //ȡ�� 
                printf("��������Ҫȡ���Ŀ�ݵ��ţ�");
                scanf("%d",&pacnum);
                for(int i=0;i<package_Count;i++){
                        if((pac[i].num==pacnum)&&(strcmp(pac[i].state,"pick")==0)&&strcmp(s[temp].phone,pac[i].stu_phone)==0){
                        printf("�����ݹ�λ�ã�");
                        scanf("%s",&location[1]);
                        printf("����ȡ���룺");
                        scanf("%s",&code[1]);
                        if((strcmp(pac[i].location,&location[1])==0)&&(strcmp(pac[i].code,&code[1])==0)){
                            printf("ȡ���ɹ���");
                            p=1;
                            strcpy(pac[i].state,"finish");                             //���״̬��Ϊ"finish"��ȡ��״̬ 
                        }
                    }
                }
                    if(p==0){
                        printf("failure!");
                    }
                break;
            case 0:                                                                    //�������ݲ��˳�ϵͳ 
                save_student_information((char*)"student.txt");                        //����ѧ�����ݵ�student.txt 
                save_package_information((char*)"package.txt");                        //���������ݵ�package.txt 
                exit_system();                                                         //�˳�ϵͳ 
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
//ѧ���޸ĸ�����Ϣ
void stu_modify(){
    int temp;
    int choice;
    temp=stu_search(user_num);
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
            case 1:                                                                   //�޸����� 
                printf("��������������");
                scanf("%s",s[temp].name);
                break;
            case 2:                                                                   //�޸��ֻ�
                printf("���������ֻ����룺");
                scanf("%s",s[temp].phone);
                break;
            case 3:                                                                   //�޸����� 
                printf("�����������룺");
                scanf("%s",s[temp].password);
                break;
            case 0:                                                                   //����ѧ������  
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
