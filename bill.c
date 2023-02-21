#include<stdio.h>
#include<string.h>
#include<stdlib.h>



struct items{
    char item[20];
    float price;
    int qty;
};

struct orders{
    char customer[50];
    char date[50];
    int numOfitems;
    struct items itm[50];
};

void generateBillHeader(char name[50], char date[30]){
    printf("\n\n");
    printf("\t  Your Restaurant");
    printf("\n\t -----------------");
    printf("\nDate:%s", date);
    printf("\nInvoice to: %s", name);
    printf("\n");
    printf("---------------------------------------\n");
    printf("Items\t\t");
    printf("Qty\t\t");
    printf("Total\t\t");
    printf("\n---------------------------------------");
    printf("\n\n");
}

void generateBillBody(char item[50], int qty, float price){
    printf("%s\t\t", item);
    printf("%d\t\t", qty);
    printf("%.2f\t\t", price);
    printf("\n");
}

void generateBillFooter(float total){
    printf("\n");
    float dis = 0.1*total;
    float netTotal = total-dis;
    float cgst = 0.09*netTotal,grandTotal = netTotal + 2*cgst;
    printf("--------------------------------------\n");
    printf("Sub Total\t\t\t%.2f", total);
    printf("\nDiscount @10%s\t\t\t%.2f", "%", dis);
    printf("\n\t\t\t\t------");
    printf("\nNet Total\t\t\t%.2f", netTotal);
    printf("\nCGST @9%s\t\t\t%.2f", "%", cgst);
    printf("\nSGST @9%s\t\t\t%.2f", "%", cgst);
    printf("\n--------------------------------------");
    printf("\nGrand Total\t\t\t%.2f", grandTotal);
    printf("\n--------------------------------------\n");
}

int main(){
    
    int opt,n;
    struct orders ord;
    struct orders order;
    char saveBill = 'y', conFlag = 'y';
    FILE *fp;
    char name[50];

    while(conFlag == 'y'){
    float total = 0;
    int invoiceFound=0;
    printf("\t===================Your Restaurant===================");
    printf("\n\nPlease select your prefered option:");
    printf("\n\n1. Create Invoice");
    printf("\n2. Show all Invoice");
    printf("\n3. Search Invoie");
    printf("\n4. Exit");

    printf("\n\nYour choice:\t");
    scanf("%d", &opt);
    fgetc(stdin);

    switch(opt){
        case 1:
        printf("\nPlease enter the name of the customer: \t");
        fgets(ord.customer,50,stdin);
        ord.customer[strlen(ord.customer)-1] = 0;
        strcpy(ord.date, __DATE__);
        printf("\nPlease enter the number of items:\t");
        scanf("%d", &n);
        ord.numOfitems = n;

        for(int i=0;i<n;i++){
            fgetc(stdin);
            printf("\n\n");
            printf("Please enter the item %d:\t", i+1);
            fgets(ord.itm[i].item,20,stdin);
            ord.itm[i].item[strlen(ord.itm[i].item)-1] = 0;
            printf("Please enter the quntity:\t");
            scanf("%d",&ord.itm[i].qty);
            printf("Please enter the unit price:\t");
            scanf("%f", &ord.itm[i].price);
            total = total + ord.itm[i].qty * ord.itm[i].price;
        }

        generateBillHeader(ord.customer, ord.date);
        for(int i=0; i<ord.numOfitems;i++){
            generateBillBody(ord.itm[i].item, ord.itm[i].qty, ord.itm[i].price);
        }
        generateBillFooter(total);

        printf("Do you want to save the invoice (y/n):\t");
        scanf("%s", &saveBill);

        if(saveBill == 'y'){
            fp = fopen("Restaurant.dat", "a+");
            fwrite(&ord,sizeof(struct orders),1,fp);
            if(fwrite != 0){
                printf("\nSuccessfully saved");
            }
            else{
                printf("\nError saving");
            }
            fclose(fp);
        }
        break;

        case 2:
        fp = fopen("Restaurant.dat", "r");
        printf("\n*********Your Previous Invoices*********\n");
        while(fread(&order, sizeof(struct orders), 1, fp)){
            float tot = 0;
            generateBillHeader(order.customer, order.date);
            for(int i=0; i<order.numOfitems;i++){
                generateBillBody(order.itm[i].item,order.itm[i].qty, order.itm[i].price);
                tot = tot + order.itm[i].qty*order.itm[i].price;
            }
            generateBillFooter(tot);
        }
        fclose(fp);
        break;

        case 3:
        printf("\nEnter the name of customer:\t");
        fgets(name,50,stdin);
        name[strlen(name)-1] = 0;

        fp = fopen("Restaurant.dat", "r");
        printf("\n*********Invoice of %s*********\n", name);

        if(!strcmp(order.customer,name)){
            while(fread(&order, sizeof(struct orders), 1, fp)){
            float tot = 0;
            generateBillHeader(order.customer, order.date);
            for(int i=0; i<order.numOfitems;i++){
                generateBillBody(order.itm[i].item,order.itm[i].qty, order.itm[i].price);
                tot = tot + order.itm[i].qty*order.itm[i].price;
            }
            generateBillFooter(tot);
            invoiceFound = 1;
         }  
        }
        if(!invoiceFound){
            printf("Sorry, the invoice for %s does not exist\n", name);

        }
        fclose(fp);
        break;

        case 4:
        printf("Bye Bye......\n\n");
        exit(0);
        break;

        default:
        printf("\nSorry invalid option");
        break;


    }
    printf("\nDo you want to continue (y/n):\t");
    scanf("%c", &conFlag);
    fgetc(stdin);
    }
    printf("\n\n");

    return 0;
}