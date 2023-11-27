#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int i,j;
int main_exit;
void menu();
void close();
struct {
    char name[60];
    int acc_no,age;
    char address[60];
    char citizenship[15];
    double phone;
    char acc_type[10];
    float amt;
    float fixed_amt;
    int time;
    }add,upd,check,rem,transaction;



void new_acc()

{
    int choice;
    FILE *ptr;

    ptr=fopen("record.txt","a+");
    account_no:
    printf("\t\t\t==== ADD RECORD  ====");
    printf("\nEnter the account number:");
    scanf("%d",&check.acc_no);
    while(fscanf(ptr,"%d %s %d %s %s %lf %s %f %f %d\n",&add.acc_no,add.name,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.fixed_amt,&add.time)!=EOF)
    {
        if (check.acc_no==add.acc_no)
            {printf("Account no. already in use!");
            
                goto account_no;

            }
    }
    add.acc_no=check.acc_no;
    printf("\nEnter the name:");
    scanf("%s",add.name);
    printf("\nEnter the age:");
    scanf("%d",&add.age);
    printf("\nEnter the address:");
    scanf("%s",add.address);
    printf("\nEnter the citizenship :");
    scanf("%s",add.citizenship);
    printf("\nEnter the phone number: ");
    scanf("%lf",&add.phone);
    printf("\nEnter the amount to deposit:");
    scanf("%f",&add.amt);
    
    

        fprintf(ptr,"%d %s %d %s %s %.0lf %s %f %f %d\n",add.acc_no,add.name,add.age,add.address,add.citizenship,add.phone,"saving",add.amt,NULL,NULL);


    fclose(ptr);
    printf("\nAccount created successfully!");
    add_invalid:
    printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d",&main_exit);
    if (main_exit==1)
        menu();
    else if(main_exit==0)
            close();
    else
        {
            printf("\nInvalid!\a");
            goto add_invalid;
        }
}
void view_list()
{
    FILE *view;
    view=fopen("record.txt","r");
    int test=0;
    printf("\nACC. NO.\tNAME\t\t\tADDRESS\t\t\tPHONE\n");

    while(fscanf(view,"%d %s %d %s %s %lf %s %f %f %d",&add.acc_no,add.name,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.fixed_amt,&add.time)!=EOF)
       {
           printf("\n%6d\t %10s\t\t\t%10s\t\t%.0lf",add.acc_no,add.name,add.address,add.phone);
           test++;
       }

    fclose(view);
    if (test==0)
        {   
            printf("\nNO RECORDS!!\n");}

    view_list_invalid:
     printf("\n\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        if (main_exit==1)
            menu();
        else if(main_exit==0)
            close();
        else
        {
            printf("\nInvalid!\a");
            goto view_list_invalid;
        }
}
void edit(void)
{
    int choice,test=0;
    FILE *old,*newrec;
    old=fopen("record.txt","r");
    newrec=fopen("new.txt","w");

    printf("\nEnter the account no. of the customer whose info you want to change:");
    scanf("%d",&upd.acc_no);
    while(fscanf(old,"%d %s %d %s %s %lf %s %f %f %d",&add.acc_no,add.name,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.fixed_amt,&add.time)!=EOF)
    {
        if (add.acc_no==upd.acc_no)
        {   test=1;
            printf("\nWhich information editdo you want to change?\n1.Address\n2.Phone\n\nEnter your choice(1 for address and 2 for phone):");
            scanf("%d",&choice);
            if(choice==1)
                {printf("Enter the new address:");
                scanf("%s",upd.address);
                fprintf(newrec,"%d %s %d %s %s %.0lf %s %f %f %d\n",add.acc_no,add.name,add.age,upd.address,add.citizenship,add.phone,add.acc_type,add.amt,add.fixed_amt,add.time);
                printf("Changes saved!");
                }
            else if(choice==2)
                {
                printf("Enter the new phone number:");
                scanf("%lf",&upd.phone);
                fprintf(newrec,"%d %s %d %s %s %.0lf %s %f %f %d\n",add.acc_no,add.name,add.age,add.address,add.citizenship,upd.phone,add.acc_type,add.amt,add.fixed_amt,add.time);
                printf("Changes saved!");
                }

        }
        else
            fprintf(newrec,"%d %s %d %s %s %.0lf %s %f %f %d\n",add.acc_no,add.name,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.fixed_amt,add.time);
    }
    fclose(old);
    fclose(newrec);
    remove("record.txt");
    rename("new.txt","record.txt");

if(test!=1)
        {  
            printf("\nRecord not found!!\a\a\a");
            edit_invalid:
              printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
              scanf("%d",&main_exit);
              
                 if (main_exit==1)

                    menu();
                else if (main_exit==2)
                    close();
                else if(main_exit==0)
                    edit();
                else
                    {printf("\nInvalid!\a");
                    goto edit_invalid;}
        }
    else
        {printf("\n\n\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        
        if (main_exit==1)
            menu();
        else
            close();
        }
}

void transact(void)
{   int choice,test=0;
    FILE *old,*newrec;
    old=fopen("record.txt","r");
    newrec=fopen("new.txt","w");

        printf("Enter the account no. of the customer:");
    scanf("%d",&transaction.acc_no);
    while (fscanf(old,"%d %s %d %s %s %lf %s %f %f %d",&add.acc_no,add.name,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.fixed_amt,&add.time)!=EOF)
   {

            if(add.acc_no==transaction.acc_no)
            {   test=1;
	        printf("\n\n customer name:%s",add.name);
                printf("\n\nDo you want to\n1.Deposit\n2.Withdraw?\n\nEnter your choice: ");
                scanf("%d",&choice);
                if (choice==1)
                {
                    printf("Enter the amount you want to deposit:$ ");
                    scanf("%f",&transaction.amt);
                    add.amt+=transaction.amt;
                    fprintf(newrec,"%d %s %d %s %s %lf %s %f %f %d\n",add.acc_no,add.name,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.fixed_amt,add.time);
                    printf("\n\nDeposited successfully!");
                    printf("\n\nUpdated balance:%f",add.amt);
			break;

                }
                else
                 {
		   
 		            printf("\n\nold balance:%.2f",add.amt);
                    printf("\n\nEnter the amount you want to withdraw:$ ");
		   
                    scanf("%f",&transaction.amt);
		    
                    add.amt-=transaction.amt;
			if(add.amt<0)
			{printf("\ninsufficient balance");
           
			menu();}
			else
            {
	                fprintf(newrec,"%d %s %d %s %s %lf %s %f %f %d\n",add.acc_no,add.name,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.fixed_amt,add.time);
                    printf("\n\nWithdraw successfully!");
                    printf("\n\nUpdated balance:%f",add.amt);
            }
	        	 }
            }
            else
            {
               fprintf(newrec,"%d %s %d %s %s %lf %s %f %f %d\n",add.acc_no,add.name,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.fixed_amt,add.time);
            }
   }
   fclose(old);
   fclose(newrec);
   remove("record.txt");
   rename("new.txt","record.txt");
   if(test!=1)
   {
       printf("\n\nRecord not found!!");
       transact_invalid:
      printf("\n\n\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
      scanf("%d",&main_exit);
      if (main_exit==0)
        transact();
    else if (main_exit==1)
        menu();
    else if (main_exit==2)
        close();
    else
    {

        printf("\nInvalid!");
        goto transact_invalid;
    }

   }
   else
   {
       printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        if (main_exit==1)
            menu();
        else
            close();
   }

}
float interest(float t,float amount,float rate)
{
    float SI;
    SI=(rate*t*amount)/100.0;
    return(SI);

}
void fixed(void)
{   int choice,test=0,famt;
    float intr,rate=10.0;
    FILE *old,*newrec;
    old=fopen("record.txt","r");
    newrec=fopen("new.txt","w");
    printf("Enter the account no. of the customer:");
    scanf("%d",&transaction.acc_no);
    while (fscanf(old,"%d %s %d %s %s %lf %s %f %f %d",&add.acc_no,add.name,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.fixed_amt,&add.time)!=EOF)
   {

            if(add.acc_no==transaction.acc_no)
            {   test=1;
	        printf("\n\n Customer name:%s",add.name);
            printf("\n\nEnter amount to be deposited for fixed deposit:");
            scanf("%f",&add.fixed_amt);
            famt=add.fixed_amt;
            printf("Enter the time period:");
                scanf("%d",&add.time);
                
            fprintf(newrec,"%d %s %d %s %s %lf %s %f %f %d\n",add.acc_no,add.name,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.fixed_amt,add.time);
                    printf("\n\nDeposited successfully!");
            intr=interest(add.time,famt,rate);
            printf("\n\nYou will get $%.2f as interest after %d year.",intr,add.time);
                
                  }
                   else
            {
               fprintf(newrec,"%d %s %d %s %s %lf %s %f %f %d\n",add.acc_no,add.name,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.fixed_amt,add.time);
            }
   }            
   fclose(old);
   fclose(newrec);
   remove("record.txt");
   rename("new.txt","record.txt");
   if(test!=1)
   {
       printf("\n\nRecord not found!!");
       transact_invalid:
      printf("\n\n\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
      scanf("%d",&main_exit);
      if (main_exit==0)
        fixed();
    else if (main_exit==1)
        menu();
    else if (main_exit==2)
        close();
    else
    {

        printf("\nInvalid!");
        goto transact_invalid;
    }

   }
   else
   {
       printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        if (main_exit==1)
            menu();
        else
            close();
   }
   
}



void see(void)
{
    FILE *ptr;
    int test=0,rate;
    int choice=1;
    float time;
    float intrst;
    ptr=fopen("record.txt","r");
    if (choice==1)
    {   printf("Enter the account number:");
        scanf("%d",&check.acc_no);

        while (fscanf(ptr,"%d %s %d %s %s %lf %s %f %f %d",&add.acc_no,add.name,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.fixed_amt,&add.time)!=EOF)
        {
            if(add.acc_no==check.acc_no)
            {   
                test=1;

                printf("\nAccount NO.:%d\nName:%s \nAge:%d \nAddress:%s \nCitizenship No:%s \nPhone number:%.0lf \nType Of Account:%s \nAmount deposited:$ %.2f \n\n",add.acc_no,add.name,
                add.age,add.address,add.citizenship,add.phone,
                add.acc_type,add.amt);
                if(strcmp(add.acc_type,"fixed")==0)
                    {
                        time=1.0;
                        rate=10;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\nYou will get $%.2f as interest on next year",intrst);
                
                   }
                 else if(strcmp(add.acc_type,"saving")==0)
                    {
                        time=(1.0/12.0);
                        rate=8;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\nYou will get $%.2f as interest on 5 of every month",intrst);

                     }
                 
                 if(add.fixed_amt>0)
                 {
                     printf("\n\nFixed Deposit: %f \n Time period: %d",add.fixed_amt,add.time);
                    intrst=interest(add.time,add.fixed_amt,10.0);
                    printf("\n\nYou will get $%.2f as interest after %d year.",intrst,add.time);
                 }

            }
        }
    }
   

    fclose(ptr);
     if(test!=1)
        {   
            printf("\nRecord not found!!\a\a\a");
            see_invalid:
              printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
              scanf("%d",&main_exit);
              
                 if (main_exit==1)
                    menu();
                else if (main_exit==2)
                    close();
                else if(main_exit==0)
                    see();
                else
                    {
                       
                        printf("\nInvalid!\a");
                        goto see_invalid;}
        }
    else
        {printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);}
        if (main_exit==1)
        {
            menu();
        }

        else
           {
            close();
            }

}


void close(void)
{
    printf("\n\n\n\nThanks for using service");
    }


void menu(void)
{   int choice;
    printf("\n\n\t\t\t       BANKING MANAGEMENT SYSTEM");
    printf("\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO THE MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\t\t[1] Create a new account\n\t\t[2] Update information of existing account\n\t\t[3] Transactions\n\t\t[4] Add Fixed Deposit\n\t\t[5] Check the details of existing account\n\t\t[6] View customer's list\n\t\t[7] Exit\n\n\n\t\t Enter your choice:");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:new_acc();
        break;
        case 2:edit();
        break;
        case 3:transact();
        break;
        case 4:fixed();
        break;
        case 5:see();
        break;
        case 6:view_list();
        break;
        case 7:close();
        break;
        default:printf("\n\n\n\t\tinvalid choice");
                add_invalid:
                printf("\n\n\n\t\tEnter 1 to return to the main menu and 0 to exit:");
                scanf("%d",&main_exit);
                if (main_exit==1)
                menu();
                else if(main_exit==0)
                close();
                else
                {
                printf("\nInvalid!\a");
                goto add_invalid;
                }
    }



}
int main()
{
    char pass[10],password[10]="pass";
    int i=0;
    printf("\n\n\n\t\t\t\t   Bank Management System\n\t\t\t\t\t User Login ");
    printf("\n\n\n\n\n\t\t\t\tEnter the password to login:");
    scanf("%s",pass);
    
    if (strcmp(pass,password)==0)
        {printf("\n\nPassword Match!");
       
            menu();
        }
    else
        {   printf("\n\nWrong password!!\a\a\a");
            login_try:
            printf("\nEnter 1 to try again and 0 to exit:");
            scanf("%d",&main_exit);
            if (main_exit==1)
                    {
                        main();
                    }

            else if (main_exit==0)
                    {
                    close();}
            else
                    {printf("\nInvalid!");
                   
                    goto login_try;}

        }
        return 0;
}
