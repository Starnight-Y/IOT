
struct package{
    int num;                        //��ݵ��� 
    char name[20];                   //�ռ������� 
    char code[20];                   //ȡ���� 
    char location[20];               //���ڿ�ݹ�λ�� 
    char stu_phone[20];              //�ռ����ֻ� 
    char cou_phone[20];              //���Ա�ֻ� 
    char state[20];                  //���״̬ 
}pac[200];

struct student{
    int num;                        //ѧ���˺� 
    char name[20];                   //ѧ������ 
    char phone[20];                  //ѧ���ֻ� 
    char password[50];               //ѧ������ 
}s[STUDENT_MAX];

struct courier{
    int num;                        //���Ա�˺� 
    char name[20];                   //���Ա���� 
    char phone[20];                  //���Ա�ֻ� 
    char password[50];               //���Ա���� 
}c[COURIER_MAX];
