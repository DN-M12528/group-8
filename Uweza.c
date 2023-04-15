#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct MembersDetails {
	char MembName[50];
	char Gender[50];
	char Email[50];
	char Contact[50];
	char BankName[50];
	float FirstContribution;
	char MembersID[50];

};
struct LoanDetails {
	float BorrowedAmount;
	char DateBorrowed[50];
	char LoanID[50];
	float AmountRepaid;
	char DateRepayed[50];
	char RepaymentID[50];

};
struct RepaymentDetails {
	float AmountRepaid;
	char DateRepayed[50];

};
struct ContributionDetails {
	float AmountContributed;
	char Month[50];
};
struct BusinessDetails {
	char BusinessName[50];
	char BusinessID[50];
	float BusinessProfit;
	char Bmonth[50];
	char BusinessLocation[50];
	char StartMonth[50];
	float Scapital;
};



int main() {
	int Option;
	struct MembersDetails Mdetails;
	struct LoanDetails Ldetails;
	struct RepaymentDetails Rdetails;
	struct ContributionDetails Cdetails;
	struct BusinessDetails Bdetails;

	/*varibles for calculating loans*/

	float LoanBalance;
	float TotalRepayment;

    //varibles on shares
    char SharesName[50];
    char SharesID[10];
    float MembShares;
    float ContGrandTotal;
    float ContSum;
    
    //variables on retrieving data.
    float Total;
    char another;
    char SearchID[10];
	char Membrecord[100];
	char Loanrecord[100];
	char Contrecord[100];
	char Businessrecord[100];
    char RepayRecords[100];
	char* token;


	printf("\t\t\tWelcome Uweza Sacco\n");
	printf("1.Members\n2.Loans\n3.Contributions\n4.Businesses\n5.Shares\n");

	char Selector ;
	
	printf("Select Option:");
	scanf("%c", &Selector);
	//return a message when you have entered the wrong option . It works well however there is a bit of problem because the words inside the printf repeats twice.
	while (Selector < '1' || Selector > '5'){
		printf("Invalid Option! Enter the correct Option:");
		scanf("%c", &Selector);
	}  
    //Operation to do with members
	if(Selector=='1') {
		printf("\n\n");
		printf("1.Register Member\n2.Search for member\n3.View All Members\n");
		printf("Select Option:");
		scanf("%d", &Option);
		fgetc(stdin);
		// Membership registration process.
		if (Option == 1) {
			do {
			printf("ID number:");
			scanf("%s", Mdetails.MembersID);
			fgetc(stdin);
			printf("Name:");
			fgets(Mdetails.MembName, sizeof(Mdetails.MembName), stdin);
			Mdetails.MembName[strlen(Mdetails.MembName)-1]=0;
			printf("Gender:");
			scanf("%s", &Mdetails.Gender);
			printf("Email:");
			scanf("%s", &Mdetails.Email);
			printf("Contact:");
			scanf("%s", &Mdetails.Contact);
			fgetc(stdin);
			while(strlen(Mdetails.Contact)!= 10  || Mdetails.Contact[0]!='0' || Mdetails.Contact[1]!= '7') {
				printf("Invalid Phone Number.Renter number:");
				scanf("%s", &Mdetails.Contact);
				fgetc(stdin);
			}
			printf("Enter Bank's Name:");
			fgets(Mdetails.BankName, sizeof(Mdetails.BankName), stdin);
			Mdetails.BankName[strlen(Mdetails.BankName)-1]=0;
			printf("Enter Members First contribution:");
			scanf("%f", &Mdetails.FirstContribution);
			FILE *Mrecords;
			Mrecords = fopen("Members_records.txt", "a");
			fprintf(Mrecords, "%s\t%s\t\t%s\t%s\t\t%s\t%s\t\t\t %.2f\n", Mdetails.MembersID, Mdetails.MembName, Mdetails.Gender, Mdetails.Email, Mdetails.Contact, Mdetails.BankName, Mdetails.FirstContribution);
			fclose(Mrecords);
			printf("Do You want to add another record?(y/n) : ");
            scanf("%s",&another);
        }while(another == 'Y' || another == 'y');
        printf("Registered succesfully");
    }

		else if (Option == 2) {
			printf("Enter Members ID:");
			scanf("%s", SearchID);
			FILE *Mreport;
			Mreport = fopen("Members_records.txt", "r");
			while(fgets(Membrecord, sizeof(Membrecord), Mreport)){
				token = strtok(Membrecord,"\t" );
				strcpy(Mdetails.MembersID, token);
				token = strtok(NULL,"\t");
				strcpy(Mdetails.MembName, token);
				token = strtok(NULL,"\t");
				strcpy(Mdetails.Gender, token);
				token = strtok(NULL,"\t");
				strcpy(Mdetails.Email, token);
				token = strtok(NULL,"\t");
				strcpy(Mdetails.Contact, token);
				token = strtok(NULL,"\t");
				strcpy(Mdetails.BankName, token);
				token = strtok(NULL,"\t");
				Mdetails.FirstContribution = atof(token);
                if(strcmp(SearchID, Mdetails.MembersID) == 0){
            	    printf("\n\n");
				    printf("Members ID        :%s\n", Mdetails.MembersID);
				    printf("Member  Name      :%s\n", Mdetails.MembName);
				    printf("Gender            :%s\n", Mdetails.Gender);
				    printf("Email             :%s\n", Mdetails.Email);
				    printf("Contact           :%s\n", Mdetails.Contact);
				    printf("Bank              :%s\n", Mdetails.BankName);
				    printf("First contribution:%f\n", Mdetails.FirstContribution);
				    printf("_________________________________________\n");
				}

            }
		}
		//viewing all members Details.
		else {
			FILE *Mreport;
			Mreport = fopen("Members_records.txt", "r");
			while(fgets(Membrecord, sizeof(Membrecord), Mreport)){
				token = strtok(Membrecord,"\t" );
				strcpy(Mdetails.MembersID, token);
				token = strtok(NULL,"\t");
				strcpy(Mdetails.MembName, token);
				token = strtok(NULL,"\t");
				strcpy(Mdetails.Gender, token);
				token = strtok(NULL,"\t");
				strcpy(Mdetails.Email, token);
				token = strtok(NULL,"\t");
				strcpy(Mdetails.Contact, token);
				token = strtok(NULL,"\t");
				strcpy(Mdetails.BankName, token);
				token = strtok(NULL,"\t");
				Mdetails.FirstContribution = atof(token);
                
                printf("\n\n");
				printf("Members ID        :%s\n", Mdetails.MembersID);
				printf("Member  Name      :%s\n", Mdetails.MembName);
				printf("Gender            :%s\n", Mdetails.Gender);
				printf("Email             :%s\n", Mdetails.Email);
				printf("Contact           :%s\n", Mdetails.Contact);
				printf("Bank              :%s\n", Mdetails.BankName);
				printf("First contribution:%f\n", Mdetails.FirstContribution);
				printf("_________________________________________\n");
			}
			fclose(Mreport);
		}
	}

	//Operations to do with loans
	else if (Selector == '2') {
		printf("\n\n");
		printf("1.Borrow Loan\n2.Loan Repayment\n3.Search for loan\n4.All loans\n");
		printf("Select Option:");
		scanf("%d", &Option);
		fgetc(stdin);
		while(Option < 1 || Option > 4){
			printf("Invalid Option!Enter the correct Option:");
			scanf("%d", &Option);
			fgetc(stdin);
		}
		//Loan borrowing process.
		if(Option == 1) {
		   do {
			printf("Members ID:");
			scanf("%s", &Mdetails.MembersID);
			fgetc(stdin);
			printf("Enter the loanID:");
			scanf("%s", Ldetails.LoanID);
			fgetc(stdin);
			printf("Enter you name:");
			fgets(Mdetails.MembName, sizeof(Mdetails.MembName), stdin);
			Mdetails.MembName[strlen(Mdetails.MembName)-1]=0;
			printf("Enter the Amount you wish to borrow:");
			scanf("%f", &Ldetails.BorrowedAmount);
			fgetc(stdin);
			printf("Date:");
			scanf("%s",&Ldetails.DateBorrowed);
			fgetc(stdin);
			FILE *Lrecords;
			Lrecords = fopen("Loan_records.txt", "a");
			fprintf(Lrecords, "%s\t\t%s\t\t%s\t\t%.2f\t\t%s\n", Mdetails.MembersID, Ldetails.LoanID, Mdetails.MembName, Ldetails.BorrowedAmount, Ldetails.DateBorrowed);
			fclose(Lrecords);
			printf("Do You want to add another record?(y/n) : ");
            scanf("%s",&another);
		}while (another == 'Y' || another=='y');
			}
		//Loan repayment process.
		else if (Option == 2){
			do {
			printf("Enter the Loan ID:");
			scanf("%s", &Ldetails.RepaymentID);
			fgetc(stdin);
			printf("Members Name:");
			fgets(Mdetails.MembName, sizeof(Mdetails.MembName), stdin);
            Mdetails.MembName[strlen(Mdetails.MembName)-1]=0;
			printf("Enter amount repaid:");
			scanf("%f",&Rdetails.AmountRepaid);
			fgetc(stdin);
			printf("Enter the date:");
			scanf("%s", &Rdetails.DateRepayed);

			FILE *Rrecords;
			Rrecords = fopen("Repayment_records.txt", "a");
			fprintf(Rrecords, "%s\t\t%s\t\t%.2f\t\t%s\n", Ldetails.RepaymentID, Mdetails.MembName, Rdetails.AmountRepaid, Rdetails.DateRepayed);
			fclose(Rrecords);

	        FILE *Rreport;
			Rreport = fopen("Repayment_records.txt", "a");
			FILE *Lreport;
			Lreport = fopen("Loan_records.txt", "r");
			while(fgets(Loanrecord, sizeof(Loanrecord), Lreport)){
				token = strtok(Loanrecord,"\t" );
				strcpy(Mdetails.MembersID, token);
				token = strtok(NULL, "\t");
				strcpy(Ldetails.LoanID, token);
				token = strtok(NULL,"\t");
				strcpy(Mdetails.MembName, token);
				token = strtok(NULL,"\t");
				Ldetails.BorrowedAmount = atof(token);
				token = strtok(NULL,"\t");
				strcpy(Ldetails.DateBorrowed, token);

			
				if (strcmp(Ldetails.LoanID, Ldetails.RepaymentID)==0){
					strcpy(SearchID, Ldetails.LoanID);
					Total = Ldetails.BorrowedAmount;
					
					 }
				}
			TotalRepayment = 0;
		    while (fgets(RepayRecords, sizeof(RepayRecords), Rreport)){
			    token = strtok(RepayRecords, "\t");
			    strcpy(Ldetails.RepaymentID, token);
			    token = strtok(NULL,"\t");
			    strcpy(Mdetails.MembName,token);
			    token = strtok(NULL,"\t");
			    Rdetails.AmountRepaid = atof(token);
			    token = strtok(NULL,"\t");
			    strcpy(Rdetails.DateRepayed,token);
			    if (strcmp(SearchID, Ldetails.RepaymentID)==0){
			    	printf("%f\n",Rdetails.AmountRepaid);
				    TotalRepayment = TotalRepayment + Rdetails.AmountRepaid;
				}
			}
			printf("%f\n", TotalRepayment);
			LoanBalance = Total - TotalRepayment;
			fclose(Rreport);
			fclose(Lreport);
	       // printf("Your laon balance is :%.2f\n", LoanBalance);
			printf("Do You want to add another record?(y/n) : ");
            scanf("%s",&another);
        }while(another == 'Y' || another == 'y');
		}
		//To view each individuals loan.
		else if (Option == 3) {
			printf("Members ID:");
			scanf("%s", &SearchID);
			FILE *Lreport;
			Lreport = fopen("Loan_records.txt", "r");
			while(fgets(Loanrecord, sizeof(Loanrecord), Lreport)){
				token = strtok(Loanrecord,"\t" );
				strcpy(Mdetails.MembersID, token);
				token = strtok(NULL, "\t");
				strcpy(Ldetails.LoanID, token);
				token = strtok(NULL,"\t");
				strcpy(Mdetails.MembName, token);
				token = strtok(NULL,"\t");
				Ldetails.BorrowedAmount = atof(token);
				token = strtok(NULL,"\t");
				strcpy(Ldetails.DateBorrowed, token);

				if(strcmp(SearchID, Mdetails.MembersID)== 0){
					printf("\n\n");
				    printf("Members ID        :%s\n", Mdetails.MembersID);
				    printf("Laon ID           :%S\n", Ldetails.LoanID);
				    printf("Member  Name      :%s\n", Mdetails.MembName);
				    printf("Amount borrowed   :%f\n", Ldetails.BorrowedAmount);
				    printf("Date borrowed     :%s\n", Ldetails.DateBorrowed);
				    printf("_________________________________________\n");
				}
			}
			fclose(Lreport);

			
		}
		else {
			FILE *Lreport;
			Lreport = fopen("Loan_records.txt", "r");
			while(fgets(Loanrecord, sizeof(Loanrecord), Lreport)){
				token = strtok(Loanrecord,"\t" );
				strcpy(Mdetails.MembersID, token);
				token = strtok(NULL,"\t");
				strcpy(Mdetails.MembName, token);
				token = strtok(NULL,"\t");
				Ldetails.BorrowedAmount = atof(token);
				token = strtok(NULL,"\t");
				strcpy(Ldetails.DateBorrowed, token);
                
                printf("\n\n");
				printf("Members ID        :%s\n", Mdetails.MembersID);
				printf("Member  Name      :%s\n", Mdetails.MembName);
				printf("Amount borrowed   :%f\n", Ldetails.BorrowedAmount);
				printf("Date borrowed     :%s\n", Ldetails.DateBorrowed);
				printf("_________________________________________\n");
			}

			fclose(Lreport);
		
		}
		//To view all Loans.
	}

	



	//Contributions
	else if (Selector == '3') {
		printf("\n\n");
		printf("1.Pay monthly Contribution\n2.Search for members contributions\n3.All the member contribution\n");
		printf("Select option:");
		scanf("%d", &Option);
		while (Option < 1 || Option > 3) {
			printf("Invalid Option, Enter the correct Option:");
			scanf("%d", &Option);
		}
        //Member contribution process.
		if (Option == 1) {
			do {
			printf("Enter MemberID:");
			scanf("%s", &Mdetails.MembersID);
			fgetc(stdin);
			printf("Enter Members Name:");
			fgets(Mdetails.MembName, sizeof(Mdetails.MembName), stdin);
			Mdetails.MembName[strlen(Mdetails.MembName)-1]=0;
			printf("Enter Amount:");
			scanf("%f", &Cdetails.AmountContributed);
			printf("Enter Month:");
			scanf("%s", &Cdetails.Month);

			FILE *Crecords;
			Crecords = fopen("Contribution_records.txt", "a");
			fprintf(Crecords, "%s\t\t%s\t\t%.2f\t\t%s\n", Mdetails.MembersID, Mdetails.MembName, Cdetails.AmountContributed, Cdetails.Month);
			fclose(Crecords);
			printf("Do You want to add another record?(y/n) : ");
            scanf("%s",&another);
		}while(another == 'Y' || another == 'y');

		}
		//Viewing specific member's details.
		else if (Option == 2) {
			printf("Enter Members ID:");
			scanf("%s", &SearchID);
			fgetc(stdin);
			FILE *Creport;
			Creport = fopen("Contribution_records.txt", "r");
			while(fgets(Contrecord, sizeof(Contrecord), Creport)){
				token = strtok(Contrecord,"\t" );
				strcpy(Mdetails.MembersID, token);
				token = strtok(NULL,"\t");
				strcpy(Mdetails.MembName, token);
				token = strtok(NULL,"\t");
				Cdetails.AmountContributed = atof(token);
				token = strtok(NULL,"\t");
				strcpy(Cdetails.Month, token);
				if(strcmp(SearchID, Mdetails.MembersID)==0){
					printf("\n\n");
				    printf("Members ID        :%s\n", Mdetails.MembersID);
				    printf("Member  Name      :%s\n", Mdetails.MembName);
				    printf("Amount borrowed   :%f\n", Cdetails.AmountContributed);
				    printf("Month Paid        :%s\n", Cdetails.Month);
				    printf("_________________________________________\n");
				}
			}
			fclose(Creport);
			
		}
		//Viewing all members details
		else {
			FILE *Creport;
			Creport = fopen("Contribution_records.txt", "r");
			while(fgets(Contrecord, sizeof(Contrecord), Creport)){
				token = strtok(Contrecord,"\t" );
				strcpy(Mdetails.MembersID, token);
				token = strtok(NULL,"\t");
				strcpy(Mdetails.MembName, token);
				token = strtok(NULL,"\t");
				Cdetails.AmountContributed = atof(token);
				token = strtok(NULL,"\t");
				strcpy(Cdetails.Month, token);

				printf("\n\n");
				printf("Members ID        :%s\n", Mdetails.MembersID);
				printf("Member  Name      :%s\n", Mdetails.MembName);
				printf("Amount borrowed   :%f\n", Cdetails.AmountContributed);
				printf("Month Paid        :%s\n", Cdetails.Month);
				printf("_________________________________________\n");
			}
			fclose(Creport);
			
		}
	}

	



	//Businesses
	else if (Selector == '4') {
		printf("\n\n");
		printf("1.Search for business records\n2.Check all Businesses\n3.Enter profits gained from the business\n4.Add new Business\n");
		printf("Select Option:");
		scanf("%d", &Option);
		fgetc(stdin);
		while (Option < 1 || Option > 4) {
			printf("Invalid Option! Enter correct Option:");
			scanf("%d", &Option);
			fgetc(stdin);
		}
		if (Option == 1) {
			printf("Enter business ID:");
			scanf("%s", &SearchID);
			fgetc(stdin);
			FILE *Breport;
			Breport = fopen("Business.txt", "r");
			while(fgets(Businessrecord, 100, Breport)){
				token = strtok(Businessrecord,"\t" );
				strcpy(Bdetails.BusinessID, token);
				token = strtok(NULL, "\t");
				strcpy(Bdetails.BusinessName, token);
				token = strtok(NULL,"\t");
				strcpy(Bdetails.BusinessLocation, token);
				token = strtok(NULL,"\t");
				Bdetails.Scapital = atof(token);
				token = strtok(NULL,"\t");
				strcpy(Bdetails.StartMonth, token);

				if(strcmp(SearchID, Bdetails.BusinessID)== 0){
					 printf("\n\n");
                printf("Business ID         :%s\n", Bdetails.BusinessID);
				printf("Business name       :%s\n", Bdetails.BusinessName);
				printf("Location            :%s\n", Bdetails.BusinessLocation);
				printf("Starting Capital    :%f\n", Bdetails.Scapital);
				printf("Month started       :%s\n", Bdetails.StartMonth);
				printf("_________________________________________\n");
				}
			}
			fclose(Breport);

				


		
		}
		else if (Option == 2) {
			FILE *Breport;
			Breport = fopen("Business.txt", "r");
			while(fgets(Businessrecord, 100, Breport)){
				token = strtok(Businessrecord,"\t" );
				strcpy(Bdetails.BusinessID, token);
				token = strtok(NULL, "\t");
				strcpy(Bdetails.BusinessName, token);
				token = strtok(NULL,"\t");
				strcpy(Bdetails.BusinessLocation, token);
				token = strtok(NULL,"\t");
				Bdetails.Scapital = atof(token);
				token = strtok(NULL,"\t");
				strcpy(Bdetails.StartMonth, token);
                
                printf("\n\n");
                printf("Business ID         :%s\n", Bdetails.BusinessID);
				printf("Business name       :%s\n", Bdetails.BusinessName);
				printf("Location            :%s\n", Bdetails.BusinessLocation);
				printf("Starting Capital    :%f\n", Bdetails.Scapital);
				printf("Month started       :%s\n", Bdetails.StartMonth);
				printf("_________________________________________\n");
			}
			fclose(Breport);
			

		}
		//Entering profits gained from the businesses
		else if (Option == 3) {
			do {
			printf("Enter the business ID:");
			scanf("%s", &Bdetails.BusinessID);
			fgetc(stdin);
            printf("Enter the Business Name:");
			fgets(Bdetails.BusinessName, sizeof(Bdetails.BusinessName), stdin);
			Bdetails.BusinessName[strlen(Bdetails.BusinessName)-1]=0;
			printf("Enter the Profits:");
			scanf("%f", &Bdetails.BusinessProfit);
			fgetc(stdin);
			printf("Month:");
			scanf("%s", &Bdetails.Bmonth);

			FILE *Brecords;
			Brecords = fopen("Businessrecords.txt", "a");
			fprintf(Brecords, "%s\t\t%s\t\t%.2f\t\t%s\n", Bdetails.BusinessID, Bdetails.BusinessName, Bdetails.BusinessProfit, Bdetails.Bmonth);
			fclose(Brecords);
			printf("Do You want to add another record?(y/n) : ");
            scanf("%s",&another);
        }while(another == 'Y' || another == 'y');
		}
		//Entering details of a new business.
		else {
			do {
			printf("Enter business ID:");
			scanf("%s", Bdetails.BusinessID);
			fgetc(stdin);
			printf("Enter the Business Name:");
			fgets(Bdetails.BusinessName, sizeof(Bdetails.BusinessName), stdin);
			Bdetails.BusinessName[strlen(Bdetails.BusinessName)-1]=0;
			printf("Enter the location of the business:");
			fgets(Bdetails.BusinessLocation, sizeof(Bdetails.BusinessLocation), stdin);
			Bdetails.BusinessName[strlen(Bdetails.BusinessName)-1]=0;
			printf("Enter date started:");
			scanf("%s", &Bdetails.StartMonth);
			fgetc(stdin);
			printf("Enter Starting Capital:");
			scanf("%f", &Bdetails.Scapital);

			FILE *B2records;
			B2records = fopen("Business.txt", "a");
			fprintf(B2records, "%s\t\t%s\t\t%.2f\t\t%s\n", Bdetails.BusinessName, Bdetails.BusinessLocation, Bdetails.Scapital, Bdetails.StartMonth);
		
			fclose(B2records);
			printf("Do You want to add another record?(y/n) : ");
            scanf("%s",&another);
		}while(another == 'Y' || another == 'y');

		}
	}

	//Shares
	else if (Selector == '5') {
		printf("\n\n");
		printf("1.Search Member shares\n2.View all members shares\n");
		printf("Select Option:");
		scanf("%d", &Option);
		while (Option < 1 || Option > 2) {
			printf("Invalid Option! Enter the correct Option:");
			scanf("%d", &Option);
		}
		if (Option == 1) {
			printf("Enter Members ID:");
			scanf("%s", &SearchID);
			fgetc(stdin);
			FILE *Creport;
			Creport = fopen("Contribution_records.txt", "r");
			ContSum = 0;
			ContGrandTotal = 0;
			while(fgets(Contrecord, sizeof(Contrecord), Creport)){
				token = strtok(Contrecord,"\t" );
				strcpy(Mdetails.MembersID, token);
				token = strtok(NULL,"\t");
				strcpy(Mdetails.MembName, token);
				token = strtok(NULL,"\t");
				Cdetails.AmountContributed = atof(token);
				token = strtok(NULL,"\t");
				strcpy(Cdetails.Month, token);
				if(strcmp(SearchID, Mdetails.MembersID)==0){
					ContSum = Cdetails.AmountContributed + ContSum;
					strcpy(SharesID, Mdetails.MembersID);
					strcpy(SharesName, Mdetails.MembName);
					

				}
				ContGrandTotal = Cdetails.AmountContributed + ContGrandTotal;
			}
			MembShares = ContSum / ContGrandTotal * 100;
			printf("Members ID :%s\n", SharesID);
			printf("Name       :%s\n", SharesName);
			printf("Shares     :%.0f %%", MembShares);
			fclose(Creport);
			
		}
		else {
			printf("here is the report for all members' shares.");
		}

	}
	
}








