extern int package_Count;
extern int user_num;
//������ݺ���
int package_search(int package_num){
    int i;
    for(i=0;i<package_Count;i++){
        if(pac[i].num==package_num) return i;
    }
    return NO_FOUND;
}
//����Ա��¼������֤ 
int admin_land(){
    int i=1,j;
    char user_name[15];
    char admin_pwd[15];
    char pwd;
    do{
        printf("\n���������Ա�û�����");
        scanf("%s",user_name);
        printf("\n���������Ա����:");
        system("stty -echo");
        pwd=getchar();
        scanf("%s",&pwd);
        system("stty echo");
        if((strcmp(user_name,ADMIN_PASSWARD)==0 && strcmp(&pwd,ADMIN_PASSWARD)==0)){
            return YES;
        }
        else
            printf("\n�������");
        printf("���������룡\n");
        i++;
        printf("---------------------------------------------------\n");
    }while(i<=3);
    return NO;
} 
//����Ա�������˵�
int admin_menu(){
    int choice=-1;
	printf("\n\n");
    printf("\t\t ----------------------------------------------------\n");
    printf("\t\t|                   ����Ա����ϵͳ                   |\n");
    printf("\t\t|----------------------------------------------------|\n");
    printf("\t\t|                                                    |\n");
    printf("\t\t|           [1]----------------ά��ѧ����Ϣ          |\n");
    printf("\t\t|           [2]----------------ά�������Ϣ          |\n");
    printf("\t\t|                                                    |\n");
    printf("\t\t|                                                    |\n");
    printf("\t\t|           [0]----------------�˳�ϵͳ              |\n");
    printf("\t\t|                                                    |\n");
    printf("\t\t ----------------------------------------------------\n");
    printf("����������ѡ��");
    scanf("%d",&choice);
    return choice;
}
//����Ա���ܿ��ƺ���
void administrator(){
    int choice;
    system("./clear.sh");
    do{
        choice=admin_menu();
        system("./clear.sh");
        switch(choice){
            case 1:
                manage_student();
                break;
            case 2:
                manage_package();
                break;
            case 0:
                save_package_information((char*)"package.txt");
                save_student_information((char*)"student.txt");
                exit_system();
                break;
            default:
                printf("\n�Բ�����ѡ�����\n");
                break;
        }
        system("./clear.sh");
    }while(1);
} 
//ά��ѧ����Ϣ�Ĳ˵��Ϳ���
void manage_student(){
    int choice;
    int num;
    do{
    	printf("\n\n");
        printf("\t\t ----------------------------------------------------\n");
        printf("\t\t|                  ѧ��ά������ϵͳ                  |\n");
        printf("\t\t|----------------------------------------------------|\n");
        printf("\t\t|                                                    |\n");
        printf("\t\t|           [1]----------------¼��ѧ����Ϣ          |\n");
        printf("\t\t|           [2]----------------���ѧ����Ϣ          |\n");
        printf("\t\t|           [3]----------------ɾ��ѧ����Ϣ          |\n");
        printf("\t\t|           [4]----------------�޸�ѧ����Ϣ          |\n");
        printf("\t\t|           [0]----------------ȡ��                  |\n");
        printf("\t\t|                                                    |\n");
        printf("\t\t ----------------------------------------------------\n"); 
        printf("��ѡ��");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                add_student();
                break;
            case 2:
                display_all_student();
                break;
            case 3:
                dele_student();
                break;
            case 4:
                printf("������Ҫ�޸ĵ�ѧ���˺ţ�");
                scanf("%d",&num); 
                for(int i=0;i<stu_Count;i++){
                    if(s[i].num==num){
                        user_num=num;
                        stu_modify();                        
                    }
                    else{
                        printf("δ�ҵ�ѧ���˺ţ�");
                    }
                }
            case 0:
                return;
            default:
                printf("\n�Բ�����ѡ�����\n");
                break;
        }
        printf("\n\n\n\n��Enter�����ء���");
        getchar();
        if(getchar()) system("./clear.sh");      
    }while(1);
}
//����Ա¼����ѧ��
void add_student(){
    int i;
    char judge;
    printf("\n\n");
    printf("�����˺ţ�");
    scanf("%d",&s[stu_Count].num);
    printf("����������");
    scanf("%s",s[stu_Count].name);
    printf("�����ֻ��ţ�");
    scanf("%s",s[stu_Count].phone);
    printf("�������룺");
    scanf("%s",s[stu_Count].password);
    getchar();
    printf("\n\n\n����¼���������ɣ����Ƿ�Ҫ����¼�����Ϣ��\n");
    printf("\n\"��\" �밴 Y");
    printf("\n\"��\" �밴 N\n");
    judge=getchar();
    if(judge=='Y' || judge=='y'){
        stu_Count++;
    }
    else
        printf("\n\n��Ϣδ���棡\n");
}
//ע����ѧ��
void regs_student(){
    int i;
    char judge;
    printf("\n\n");
    printf("�����˺ţ�");
    scanf("%d",&s[stu_Count].num);
    printf("\n"); 
    printf("����������");
    scanf("%s",s[stu_Count].name);
    printf("\n"); 
    printf("�����ֻ��ţ�");
    scanf("%s",s[stu_Count].phone);
    printf("\n"); 
    printf("�������룺");
    scanf("%s",s[stu_Count].password);
    printf("\n"); 
    getchar();
    printf("\n\n\n����¼���������ɣ����Ƿ�Ҫ����¼�����Ϣ��\n");
    printf("\n\"��\" �밴 Y");
    printf("\n\"��\" �밴 N\n");
    judge=getchar();
    if(judge=='Y' || judge=='y'){
        stu_Count++;
    }
    else
        printf("\n\nע��ʧ�ܣ�\n");
    if(getchar()) system("./clear.sh");
}
//ע���¿��Ա
void regs_courier(){
    int i;
    char judge;
    printf("\n\n");
    printf("�����˺ţ�");
    scanf("%d",&c[cou_Count].num);
    printf("\n"); 
    printf("����������");
    scanf("%s",c[cou_Count].name);
    printf("\n"); 
    printf("�����ֻ��ţ�");
    scanf("%s",c[cou_Count].phone);
    printf("\n"); 
    printf("�������룺");
    scanf("%s",c[cou_Count].password);
    printf("\n"); 
    getchar();
    printf("\n\n\n����¼���������ɣ����Ƿ�Ҫ����¼�����Ϣ��\n");
    printf("\n\"��\" �밴 Y");
    printf("\n\"��\" �밴 N\n");
    judge=getchar();
    if(judge=='Y' || judge=='y'){
        cou_Count++;
    }
    else
        printf("\n\nע��ʧ�ܣ�\n");
    if(getchar()) system("./clear.sh");
} 
//����Ա���ѧ���Ļ�����Ϣ
void display_all_student(){
    int i;
    for(i=0;i<stu_Count;i++)
        printf("�˺ţ�%d\t������%s\t�ֻ����룺%s\t���룺%s\n",s[i].num,s[i].name,s[i].phone,s[i].password);
}
//����Աɾ��ѧ��
void dele_student(){
    int j=0,temp;
    int stu_num;
    char judge;
    printf("\n������Ҫɾ��ѧ�����˺ţ�");
    scanf("%d",&stu_num);
    getchar();
    if((temp=stu_search(stu_num))==NO_FOUND)
        printf("\n�Բ��𣬸��û���Ϣ�����ڣ�\n");
    else{
        printf("\n\n\n��ȷ��Ҫɾ��ѧ��Ϊ%d��ѧ����\n",stu_num);
        printf("\n\"��\" �밴 Y");
        printf("\n\"��\" �밴 N\n");
        judge=getchar();
        if(judge=='Y'||judge=='y'){
            for(j=temp;j<=stu_Count-1;j++){
                s[j]=s[j+1];
            }
            stu_Count--;
            printf("\nɾ����Ϣ��ɣ�");
        }
        else
            printf("\n\n����δɾ��ѧ��Ϊ%d��ѧ����\n",stu_num);
    }
}
//ά�������Ϣ�Ĳ˵��Ϳ���
void manage_package(){
    int choice;
    int num;
    int p=0;
    do{
    	printf("\n\n");
        printf("\t\t ----------------------------------------------------\n");
        printf("\t\t|                  ���ά������ϵͳ                  |\n");
        printf("\t\t|----------------------------------------------------|\n");
        printf("\t\t|                                                    |\n");
        printf("\t\t|           [1]----------------��������Ϣ          |\n");
        printf("\t\t|           [2]----------------�޸Ŀ����Ϣ          |\n");
        printf("\t\t|           [3]----------------����ݴ����ݹ�      |\n");
        printf("\t\t|                                                    |\n");
        printf("\t\t|           [0]----------------ȡ��                  |\n");
        printf("\t\t|                                                    |\n");
        printf("\t\t ----------------------------------------------------\n"); 
        printf("��ѡ��");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                display_all_package();
                break;
            case 2:
                pac_modify();
                break;
            case 3:
                printf("��������ݹ�Ŀ�ݵ��ţ�");
                scanf("%d",&num); 
                for(int i=0;i<package_Count;i++){
                    if(strcmp(pac[i].state,"arrival")==0&&pac[i].num==num){
                        printf("�������ݹ�λ�ã�");
                        scanf("%s",pac[i].location);
                        printf("������ȡ���룺");
                        scanf("%s",pac[i].code); 
                        printf("��ųɹ���");
                        strcpy(pac[i].state,"pick");
                        p=1;
                    }                  
                } 
                if(p==0){
                    printf("default!");
                }
                break;               
            case 0:
                return;
            default:
                printf("\n�Բ�����ѡ�����\n");
                break;
        }
        printf("\n\n\n\n��Enter�����ء���");
        getchar();
        if(getchar()) system("./clear.sh");       
    }while(1);
}
//��ӿ�ݺ��� 
void add_package(){
    int i;
    char judge;
    printf("\n\n");
    printf("�����ݵ��ţ�");
    scanf("%d",&pac[package_Count].num);
    printf("�����ռ��ˣ�");
    scanf("%s",pac[package_Count].name);
    printf("����ѧ���ֻ��ţ�");
    scanf("%s",pac[package_Count].stu_phone);
    printf("������Ա�ֻ��ţ�");
    scanf("%s",pac[package_Count].cou_phone);
    strcpy(pac[package_Count].state,"delivery");
    strcpy(pac[package_Count].code,"0");
    strcpy(pac[package_Count].location,"0");    
    getchar();
    printf("\n\n\n����¼���������ɣ����Ƿ�Ҫ����¼�����Ϣ��\n");
    printf("\n\"��\" �밴 Y");
    printf("\n\"��\" �밴 N\n");
    judge=getchar();
    if(judge=='Y' || judge=='y'){
        package_Count++;
    }
    else{
        printf("\n\n��Ϣδ���棡\n");
    }
}
//��������Ϣ
void display_all_package(){
    int i;
    for(i=0;i<package_Count;i++){
        printf("��ݵ��ţ�%d\t",pac[i].num);
        printf("�ռ��ˣ�%s\t",pac[i].name);
        printf("�ռ����ֻ���%s\t",pac[i].stu_phone);
        printf("���Ա�ֻ���%s\t",pac[i].cou_phone);
        printf("���ڿ�ݹ�λ�ã�%s\t",pac[i].location);
        printf("���״̬��%s\t",pac[i].state);
        printf("ȡ���룺%s\n",pac[i].code);
    }
}
//�޸Ŀ�ݺ���
void pac_modify(){
    int temp;
    int choice;
    int id,p=0,o;
    printf("�������ݵ���:");
    scanf("%d",&id);
    for(int i=0;i<package_Count;i++){
        if(id==pac[i].num){
            o=1;
            p=i;   
        }
    }
    if(o==1){
    system("./clear.sh");
    do{
        printf("\n\n");
        printf("\t\t ----------------------------------------------------\n");
        printf("\t\t|                ��ѡ����Ҫ�޸ĵ���Ϣ                |\n");
        printf("\t\t|----------------------------------------------------|\n");
        printf("\t\t|                                                    |\n");
        printf("\t\t|           ���״̬                 �밴 1          |\n");
        printf("\t\t|           ȡ����                   �밴 2          |\n");
        printf("\t\t|           ��ݹ�λ��               �밴 3          |\n");
        printf("\t\t|                                                    |\n");
        printf("\t\t|           ȡ��                     �밴 0          |\n");
        printf("\t\t|                                                    |\n");
        printf("\t\t ----------------------------------------------------\n");
        printf("��ѡ��");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("��������״̬��");
                scanf("%s",pac[p].state);
                break;
            case 2:
                printf("������ȡ���룺");
                scanf("%s",pac[p].code);
                break;
            case 3:
                printf("�������ݹ�λ�ã�");
                scanf("%s",pac[p].location);
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
    else{
        printf("no result!");
    }
}
//��������Ϣ
void Load_package_information(char * file_name){
    FILE *fp;
    struct package *p;
    if((fp=fopen(file_name,"r"))==NULL){
        printf("δ�ҵ������ļ���\n");
        return;
    }
    while(!feof(fp)){
        p=(struct package *)malloc(sizeof(struct package));
        if(fscanf(fp,"%d%s%s%s%s%s%s\r",&p->num,p->name,p->code,p->location,p->stu_phone,p->cou_phone,p->state)==0){
            printf("�����ļ�����ʧ��!\n");
            return;
        }
        pac[package_Count]=*p;
        package_Count++;
    }
    printf("package_Count=%d",package_Count);
    free(p);
    fclose(fp);
    printf("\n�����ļ�������!\n\n");
}
//����ѧ����Ϣ 
void Load_student_information(char * file_name){
    FILE *fp;
    struct student *p;
    if((fp=fopen(file_name,"r"))==NULL){
        printf("δ�ҵ��û��ļ���\n");
        return;
    }
    while(!feof(fp)){
        p=(struct student *)malloc(sizeof(struct student));
        if(fscanf(fp,"%d%s%s%s\r",&p->num,p->name,p->phone,p->password)==0){
            printf("�û��ļ�����ʧ��!\n");
            return;
        }
        s[stu_Count]=*p;
        stu_Count++;
    }
    printf("stu_Count=%d",stu_Count);
    free(p);
    fclose(fp);
    printf("\nѧ���ļ�������!\n\n");
}
//������Ա��Ϣ 
void Load_courier_information(char * file_name){
    FILE *fp;
    struct courier *p;
    if((fp=fopen(file_name,"r"))==NULL){
        printf("δ�ҵ��û��ļ���\n");
        return;
    }
    while(!feof(fp)){
        p=(struct courier *)malloc(sizeof(struct courier));
        if(fscanf(fp,"%d%s%s%s\r",&p->num,p->name,p->phone,p->password)==0){
            printf("�û��ļ�����ʧ��!\n");
            return;
        }
        c[cou_Count]=*p;
        cou_Count++;
    }
    printf("cou_Count=%d",cou_Count);
    free(p);
    fclose(fp);
    printf("\n���Ա�ļ�������!\n\n");
}
//��������Ϣ 
void save_package_information(char *file_name){
    FILE *fp;
    struct package *p;
    int i;
    if((fp=fopen(file_name,"w"))==NULL)
        printf("δ�ҵ������ļ�,���ܱ���!\n");
    for(i=0;i<package_Count;i++){
        p=(struct package *)malloc(sizeof(struct package));
        *p=pac[i];
        if(fprintf(fp,"%d %s %s %s %s %s %s\n",p->num,p->name,p->code,p->location,p->stu_phone,p->cou_phone,p->state)==0){
            printf("�����ļ�����ʧ��!\n");
            return;
        }
    }
    free(p);
    fclose(fp); 
    printf("�����ļ��ѱ���!\n");
}
//����ѧ����Ϣ
void save_student_information(char *file_name){
    FILE *fp;
    struct student *p;
    int i;
    if((fp=fopen(file_name,"w"))==NULL)
        printf("δ�ҵ�ѧ���ļ�,���ܱ���!\n");
    for(i=0;i<stu_Count;i++){
        p=(struct student *)malloc(sizeof(struct student));
        *p=s[i];
        if(fprintf(fp,"%d %s %s %s\n",p->num,p->name,p->phone,p->password)==0){
            printf("ѧ���ļ�����ʧ��!\n");
            return;
        }
    }
    free(p);
    fclose(fp); 
    printf("ѧ���ļ��ѱ���!\n");
}
//������Ա��Ϣ 
void save_courier_information(char *file_name){
    FILE *fp;
    struct courier *p;
    int i;
    if((fp=fopen(file_name,"w"))==NULL)
        printf("δ�ҵ����Ա�ļ�,���ܱ���!\n");
    for(i=0;i<cou_Count;i++){
        p=(struct courier *)malloc(sizeof(struct courier));
        *p=c[i];
        if(fprintf(fp,"%d %s %s %s\n",p->num,p->name,p->phone,p->password)==0){
            printf("���Ա�ļ�����ʧ��!\n");
            return;
        }
    }
    free(p);
    fclose(fp); 
    printf("���Ա�ļ��ѱ���!\n");
} 

