
#include<stdio.h>
main()
{
FILE *fptr;
 int pin;
 int pins = 2526;
 int pinTries = 1;
 int reciept;
 int options;
 int options2;
 float CA_balance = 10000;
 float withdraw;
 float deposit;
 int account;
 float SB_balance=5000;
 float TD_balance= 20000;
 float RD_balance=3000;
 fptr=fopen("c:\\emp.txt","w+");
 printf("**********WELCOME TO ATM***********\n");

printf("Enter your pin:");// the pin is 2526//
scanf("%d", &pin);
while (pinTries <3)
 {
 if (pin == pins)
 {
printf("Would you like to take a reciept:");
 //1 is equal to yes and 2 is equal to no
scanf("%d", &reciept);
printf("Enter ur choice\n");
printf("1.withdraw\n");
printf("2.Deposit\n");
printf("3.check balance\n");
printf("4.Reset ur pin\n");
scanf("%d",&options);
while (options <= 5)
 {
 switch (options)
 {
 case 1:
 printf("Enter the account\n");
 printf("1.Savings account\n");
 printf("2.Current account\n");

 scanf("%d",&account);

 printf("Enter the amount to be withdrawn\nRs.");
 scanf("%f",& withdraw);
 fprintf(fptr, "withdraw = %f\n", withdraw);
 if(account==1)
{
if(withdraw>SB_balance)
{
 printf("Insufficient balance\n");
 break;
}
else
{
 printf("\n\nTransaction successful!!!!\n\n\n");
SB_balance=SB_balance-withdraw;
 printf("The balance is:Rs.%f\n",SB_balance);
 fprintf(fptr, "SB balance = %f\n", SB_balance);
 break;

 } 
 }
 else
 {
 if(withdraw>CA_balance)
 {
 printf("insufficient balance\n");
 break;
 }
 else
 {
 printf("\n\nTransaction successful!!!!\n\n\n");
 CA_balance=CA_balance-withdraw;
 printf("The balance is: Rs.%f\n",CA_balance);
 fprintf(fptr, "CA balance = %f\n", CA_balance);
 break;
 }
 }

 case 2: printf("Enter the account\n");
 printf("1.Savings account\n");
 printf("2.Current account\n");
 printf("3.Recurring deposit account\n");
 scanf("%d",&account);
 printf("Enter the amount to be deposited\nRs.");
 scanf("%f",&deposit);
 fprintf(fptr, "deposit = %f\n", deposit);
 printf("Transaction successful!!!!\n\n\n");

 if(account==1)
 {
 SB_balance=SB_balance+deposit;
 printf("The balance is: Rs.%f\n",SB_balance);
 fprintf(fptr, "SB_balance = %f\n",SB_balance);
 break;
 }
 else if(account==2)
 {
 CA_balance=CA_balance+deposit;
 printf("The balance is: Rs.%f\n",CA_balance);
 fprintf(fptr, "CA_balance = %f\n", CA_balance);
 break;

 }

 else
 {
RD_balance=RD_balance+deposit;
printf("The balance is: Rs.%f\n",RD_balance);
fprintf(fptr, "RD_balance = %f\n", RD_balance);
 break;
 }
 case 3:
 printf("Enter the account\n");
 printf("1.Savings account\n");
 printf("2.Current account\n");
 printf("3.Term deposit account\n");
 printf("4.Recurring deposit account\n");
 scanf("%d",&account);
 if(account==1)
 {
 printf("\nThe balance in your account is :Rs.%f\n",SB_balance);
 break;
 }
 else if(account==2)
 {
 printf("\nThe balance in your account is :Rs.%f\n", CA_balance);
 break;
 }
 else if(account==3)
 {
 printf("\nThe balance in your account is :Rs.%f\n",TD_balance);
 break;
 }
 else
 {

 printf("The balance in your account is :Rs.%f\n",RD_balance);
 break;
 }


 case 4:

 printf("Enter your new pin\n");
 scanf("%d",&pin);
 printf("successfully updated new pin!!!\n\n");
 break;
 default:
 printf("Invalid choice\n");
 }
 printf("\n\nWould you like another transaction: \n");// 1 is equal to yes and 2 is equal to no
 scanf("%d", &options2);
 if(options2==2)
 {
 printf("\nThank you for using this ATM!!!\n\n Please collect your card");
 return 0;
 }
 else
{
printf("Enter ur choice\n");
printf("1.withdraw\n");
printf("2.Deposit\n");
printf("3.check balance\n");
printf("4.Reset ur pin\n");
scanf("%d", &options);
 }
 }
 }

else
 {
 printf("Invalid pin, try again:\n");
 scanf("%d", &pin);
 pinTries++;

 }
 if (pinTries == 3)
 {
 printf("Sorry, you cant continue, please contact your bank\n");
 }
 } fclose(fptr);

}

