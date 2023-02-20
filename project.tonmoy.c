#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
int a,b,b1,b2,b3,n,m,p,i,j,p1,p2,p3,c,c1,c2,l,d,d1,count,count1,count2;
char pass[10];
FILE *fe,*ff,*fk,*fec,*ffc,*fkc,*fse,*fsf,*fsk,*fsec,*fsfc,*fskc;
struct electric
{
    char subitem[10];
    float price;
    int barcode;
    char brand[10];
    char color[10];
    char material[10];
    char m_date[10];
    char e_date[10];
};
struct electric sh[50];
void structure();
void password(int a);
void print_to_file();
void take_input();
void take_input_k();
void take_input_f();
void print_to_file_k();
void print_to_file_f();
void read_from_file();
void read_from_file_k();
void read_from_file_f();
void read_from_file_eb(int b1);
void read_from_file_kb(int b2);
void read_from_file_fb(int b3);
void e_f_k_o(int p);
void add_one_item();
void product();
void sold_item_e();
void sold_item_k();
void sold_item_f();
void password1(char pass1[10]);
int main()
{
    structure();
}
void structure()
{
    system("cls");
    system("color fc");
    printf("                            ######     WELCOME TO OUR SHOP     ######\n\n\n");
    printf("                            <<<<<<<    THE SUPER SHOP MANAGEMENT SYSTEM    >>>>>>>");

    printf("\n\n \n\t\t\t\t\t1.Management system \n\n\t\t\t\t\t2.Billing \n\n\t\t\t\t\tPRESS A NUMBER:");
    scanf("%d",&a);
    password(a);

    getch();
}
void password(int a)
{
    switch(a)
    {
    case 1:
        {
            system("cls");
            system("color e0");
            printf("                            <<<<<<<    THE SUPER SHOP MANAGEMENT SYSTEM    >>>>>>>\n");
            printf("\n\n\t\t\t\t\tADMIN \n\n\t\t\t\t\tpassword:");
            scanf("%s",pass);
            password1(pass);
            break;
        }
    case 2:
        {

            system("cls");
            system("color f1");
            printf("\t\t\t\t\t<<<<<<BILLING>>>>>>\n\n\n\t\t\t\t\t1.electric items\n\n\t\t\t\t\t2.food items\n\n\t\t\t\t\t3.kitchen items\n\n\t\t\t\t\t>>>>>");
            scanf("%d",&b);
            if(b==1)
            {
                system("cls");
                system("color b0");
                printf("how many items:");
                scanf("%d",&b1);
                read_from_file_eb(b1);
                printf("\n\npress 0 to go home\n\npress 1 to bill again\n\n>>>>>");
                scanf("%d",&d);
                if(d==0)
                    structure();
                if(d==1)
                    password(a);
            }
            if(b==2)
                {
                    system("cls");
                    system("color b0");
                    printf("how many items:");
                    scanf("%d",&b3);
                    read_from_file_fb(b3);
                    printf("\n\npress 0 to go home\n\npress 1 to bill again\n\n>>>>");
                    scanf("%d",&d);
                    if(d==0)
                        structure();
                    if(d==1)
                        password(a);
                }
            if(b==3)
                {
                    system("cls");
                    system("color b0");
                    printf("how many items:");
                    scanf("%d",&b2);
                    read_from_file_kb(b2);
                    printf("\n\npress 0 to go home\n\npress 1 to bill again\n\n>>>>>>");
                    scanf("%d",&d);
                    if(d==0)
                        structure();
                    if(d==1)
                        password(a);
                }
            break;
        }
    }

}
void password1(char pass1[10])
{
    if(strcmp(pass1,"tonmoy01")==0)
        {
                    system("cls");
                    system("color e0");
                    printf("                            <<<<<<<    THE SUPER SHOP MANAGEMENT SYSTEM    >>>>>>>\n");
                    printf("\n\n\t\t\t\t\t1.Product List\n\n\t\t\t\t\t2.Sold Items\n\n\t\t\t\t\t0.logout");
                    printf("\n\n\t\t\t\t\tChoose>>>");
                    scanf("%d",&m);
                    if(m==1)
                        product();
                    if(m==2)
                        {
                        system("cls");
                        printf("Name\t\tbrand\t\tcolor\t\tprice\t\tbarcode\t\tmaterial\tm_date\t\te_date");
                        sold_item_e();
                        sold_item_k();
                        printf("\nName\t\tkg/gm/liter\tprice\t\tbarcode\t\tm_date\t\te_date");
                        sold_item_f();
                        printf("\n\nPress 0 to go back\n>>");
                        scanf("%d",&d1);
                        if(d1==0)
                            password1(pass);

                        }
                    if(m==0)
                        structure();
                }
            else
            {
                system("color c0");
                printf("\a\t\t\t\t\tIncorrect password");
                printf("\n\n\t\t\t\t\tPress 1 to try again \n\n\t\t\t\t\tPress 2 to back to HOME \n\t\t\t\t\t>>>");
                scanf("%d",&b);
                switch(b)
                {
                    case 1:
                      password(a);
                      break;
                    case 2:
                      structure();
                      break;

                }
            }
}
void product()
{
    system("cls");
    system("color f0");
    printf("\t\t\t\t\t>>>>Product List<<<< \n\n\t\t\t1.Electric Items And Goods \n\n\t\t\t2.Foods Items \n\n\t\t\t3.Kitchen Items And Goods \n\n\t\t\tPRESS 0 to go back");
    printf("\n\n\t\t\tChoose>>>");
    scanf("%d",&p);
    e_f_k_o(p);
}
void e_f_k_o(int p)
{
    if(p==0)
        password1(pass);
    if(p==1)
        {
            system("cls");
            system("color fd");
            printf("Name\t\tbrand\t\tcolor\t\tprice\t\tbarcode\t\tmaterial\tm_date\t\te_date");
            read_from_file();
            printf("\n\n1.add items\n\nPRESS 0 to go back");
            printf("\n\nChoose>>>");
            scanf("%d",&p1);
            if(p1==0)
            {
                product();
            }
            if(p1==1)
            {
                system("cls");
                system("color B0");
                take_input();
                print_to_file();
                printf("\n\nSUCCESSFULL");
                printf("\n\npress 0 to go back\n\n>>>");
                scanf("%d",&p2);
                if(p2==0)
                    e_f_k_o(p);

            }

        }
    if(p==2)
        {
           system("cls");
           system("color fd");
            printf("Name\t\tkg/gm/liter\tprice\t\tbarcode\t\tm_date\t\te_date");
            read_from_file_f();
            printf("\n\n1.add new items\n\nPRESS 0 to go back");
            printf("\n\n>>>>");
            scanf("%d",&p1);
            if(p1==0)
            {
                product();
            }
            if(p1==1)
            {
                system("cls");
                system("color B0");
                take_input_f();
                print_to_file_f();
                printf("\n\nSUCCESSFULL");
                printf("\n\npress 0 to go back\n\n>>>>");
                scanf("%d",&p2);
                if(p2==0)
                    e_f_k_o(p);

            }
        }
    if(p==3)
        {
            system("cls");
            system("color fd");
            printf("Name\t\tbrand\t\tcolor\t\tprice\t\tbarcode\t\tmaterial\tm_date\t\te_date");
            read_from_file_k();
            printf("\n\n1.add new items\n\nPRESS 0 to go back\n\n>>>>");
            scanf("%d",&p1);
            if(p1==0)
            {
                product();
            }
            if(p1==1)
            {
                system("cls");
                system("color B0");
                take_input_k();
                print_to_file_k();
                printf("\n\nSUCCESSFULL");
                printf("\n\npress 0 to go back\n\n>>>>");
                scanf("%d",&p2);
                if(p2==0)
                    e_f_k_o(p);

            }
        }
}
void take_input()
{
    printf("how many items :");
    scanf("%d",&c);
    for(i=0;i<c;i++)
    {
        printf("Name:");
        scanf("%s",sh[i].subitem);
        printf("Brand:");
        scanf("%s",sh[i].brand);
        printf("Color:");
        scanf("%s",sh[i].color);
        printf("price:");
        scanf(" %f",&sh[i].price);
        printf("Barcode:");
        scanf(" %d",&sh[i].barcode);
        printf("Material:");
        scanf(" %s",sh[i].material);
        printf("Manufacture date:");
        scanf(" %s",sh[i].m_date);
        printf("Expired date:");
        scanf(" %s",sh[i].e_date);
    }
}

void print_to_file()
{
    for(i=0;i<c;i++)
    {

        printf("\n%s",sh[i].subitem);
        printf("\t\t%s",sh[i].brand);
        printf("\t\t%s",sh[i].color);
        printf("\t\t%.2f",sh[i].price);
        printf("\t\t%d",sh[i].barcode);
        printf("\t\t%s",sh[i].material);
        printf("\t\t%s",sh[i].m_date);
        printf("\t\t%s",sh[i].e_date);
    }
    int ec1;
    fec=fopen("fec.txt","r");
    if(fec!=NULL)
    {
        fscanf(fec,"%d",&ec1);
    }
    else
    {
        ec1=0;
    }
    fclose(fec);
    fec=fopen("fec.txt","w");
    fprintf(fec,"%d",c+ec1);
    fclose(fec);

    fe=fopen("electric.txt","a");
    for(i=0;i<c;i++)
    {
        fprintf(fe,"\n%s\t\t",sh[i].subitem);
        fprintf(fe,"%s\t\t",sh[i].brand);
        fprintf(fe,"%s\t\t",sh[i].color);
        fprintf(fe,"%0.2f\t\t",sh[i].price);
        fprintf(fe,"%d\t\t",sh[i].barcode);
        fprintf(fe,"%s\t\t",sh[i].material);
        fprintf(fe,"%s\t\t",sh[i].m_date);
        fprintf(fe,"%s\t\t",sh[i].e_date);


    }
    fclose(fe);
}
void read_from_file()
{
    fec=fopen("fec.txt","r");
    fscanf(fec,"%d",&count);
    fclose(fec);
    fe=fopen("electric.txt","r");
    for(i=0;i<count;i++)
    {
        fscanf(fe,"%s",sh[i].subitem);
        fscanf(fe,"%s",sh[i].brand);
        fscanf(fe,"%s",sh[i].color);
        fscanf(fe,"%f",&sh[i].price);
        fscanf(fe,"%d",&sh[i].barcode);
        fscanf(fe," %s",sh[i].material);
        fscanf(fe," %s",sh[i].m_date);
        fscanf(fe," %s",sh[i].e_date);
        getc(fe);
    }
    fclose(fe);
    for(i=0;i<count;i++)
    {

        printf("\n%d.%s",i+1,sh[i].subitem);
        printf("\t\t%s",sh[i].brand);
        printf("\t\t%s",sh[i].color);
        printf("\t\t%0.2f",sh[i].price);
        printf("\t\t%d",sh[i].barcode);
        printf("\t\t%s",sh[i].material);
        printf("\t\t%s",sh[i].m_date);
        printf("\t\t%s",sh[i].e_date);
    }

}
void read_from_file_eb(int b1)
{
    int ec;
    fsec=fopen("electric_count.txt","r");
    if(fsec!=NULL)
    {
        fscanf(fsec,"%d",&ec);
    }
    else
    {
        ec=0;
    }
    fclose(fsec);
    fsec=fopen("electric_count.txt","w");
    fprintf(fsec,"%d",ec+b1);
    fclose(fsec);

    int s1;
    float sum=0;

    fse=fopen("electric_item.txt","a");
    for(l=0;l<b1;l++)
    {
        printf("\nenter the barcode of items:");
        scanf("%d",&j);

    fe=fopen("electric.txt","r");
    fec=fopen("fec.txt","r");
    fscanf(fec,"%d",&count);
    fclose(fec);
    i=0;
    while(i<count)
    {
        fscanf(fe,"%s",sh[i].subitem);
        fscanf(fe,"%s",sh[i].brand);
        fscanf(fe,"%s",sh[i].color);
        fscanf(fe,"%f",&sh[i].price);
        fscanf(fe,"%d",&sh[i].barcode);
        fscanf(fe," %s",sh[i].material);
        fscanf(fe," %s",sh[i].m_date);
        fscanf(fe," %s",sh[i].e_date);
        getc(fe);
        i++;
    }
    fclose(fe);
    i=0;
    while(i<count)
    {
        if(i==j)
        {
        printf("\n%d.%s",i+1,sh[i].subitem);
        printf("\t\t%s",sh[i].brand);
        printf("\t\t%s",sh[i].color);
        printf("\t\t%0.2f",sh[i].price);
        printf("\t\t%d",sh[i].barcode);
        printf("\t\t%s",sh[i].material);
        printf("\t\t%s",sh[i].m_date);
        printf("\t\t%s",sh[i].e_date);
        sum+=sh[i].price;
        }
        i++;
    }
     i=0;
    while(i<count)
    {
        if(i==j)
        {
        fprintf(fse,"\n%s",sh[i].subitem);
        fprintf(fse,"\t\t%s",sh[i].brand);
        fprintf(fse,"\t\t%s",sh[i].color);
        fprintf(fse,"\t\t%0.2f",sh[i].price);
        fprintf(fse,"\t\t%d",sh[i].barcode);
        fprintf(fse,"\t\t%s",sh[i].material);
        fprintf(fse,"\t\t%s",sh[i].m_date);
        fprintf(fse,"\t\t%s",sh[i].e_date);
        }
        i++;
    }
    }
    printf("\n\nTotal: %0.2f tk",sum);
    fclose(fse);

}
void read_from_file_kb(int b2)
{
    int kc;
    fskc=fopen("kitchen_count.txt","r");
    if(fskc!=NULL)
    {
        fscanf(fskc,"%d",&kc);
    }
    else
    {
        kc=0;
    }
    fclose(fskc);
    fskc=fopen("kitchen_count.txt","w");
    fprintf(fskc,"%d",kc+b2);
    fclose(fskc);
    float sum1=0;
    fsk=fopen("kitchen_item.txt","a");
    for(m=0;m<b2;m++)
    {
        printf("\nenter the barcode of items:");
        scanf("%d",&j);


    fk=fopen("kitchen.txt","r");
    fkc=fopen("fkc.txt","r");
    fscanf(fkc,"%d",&count1);
    fclose(fkc);
    for(i=0;i<count1;i++)
    {

        fscanf(fk,"%s",sh[i].subitem);
        fscanf(fk,"%s",sh[i].brand);
        fscanf(fk,"%s",sh[i].color);
        fscanf(fk,"%f",&sh[i].price);
        fscanf(fk,"%d",&sh[i].barcode);
        fscanf(fk," %s",sh[i].material);
        fscanf(fk," %s",sh[i].m_date);
        fscanf(fk," %s",sh[i].e_date);


    }
    fclose(fk);
    for(i=0;i<count1;i++)
    {
        if(i==j)
        {
        printf("\n%d.%s",i+1,sh[i].subitem);
        printf("\t\t%s",sh[i].brand);
        printf("\t\t%s",sh[i].color);
        printf("\t\t%0.2f",sh[i].price);
        printf("\t\t%d",sh[i].barcode);
        printf("\t\t%s",sh[i].material);
        printf("\t\t%s",sh[i].m_date);
        printf("\t\t%s",sh[i].e_date);
        sum1+=sh[i].price;
        }
    }
    for(i=0;i<count1;i++)
    {
        if(i==j)
        {
        fprintf(fsk,"%s",sh[i].subitem);
        fprintf(fsk,"\t\t%s",sh[i].brand);
        fprintf(fsk,"\t\t%s",sh[i].color);
        fprintf(fsk,"\t\t%0.2f",sh[i].price);
        fprintf(fsk,"\t\t%d",sh[i].barcode);
        fprintf(fsk,"\t\t%s",sh[i].material);
        fprintf(fsk,"\t\t%s",sh[i].m_date);
        fprintf(fsk,"\t\t%s",sh[i].e_date);
        }
    }
    }
    printf("\n\nTotal: %0.2f tk",sum1);
    fclose(fsk);

}
void read_from_file_fb(int b3)
{
    int fc;
    fsfc=fopen("food_count.txt","r");
    if(fsfc!=NULL)
    {
        fscanf(fsfc,"%d",&fc);
    }
    else
    {
        fc=0;
    }
    fclose(fsfc);
    fsfc=fopen("food_count.txt","w");
    fprintf(fsfc,"%d",fc+b3);
    fclose(fsfc);
    float sum2=0;
    fsf=fopen("food_items.txt","a");
    for(n=0;n<b3;n++)
    {
        printf("\nenter the barcode of items:");
        scanf("%d",&j);

        ff=fopen("food.txt","r");
        ffc=fopen("ffc.txt","r");
        fscanf(ffc,"%d",&count2);
        fclose(ffc);
        for(i=0;i<count2;i++)
        {
        fscanf(ff,"%s",sh[i].subitem);
        fscanf(ff,"%s",sh[i].brand);
        fscanf(ff,"%f",&sh[i].price);
        fscanf(ff,"%d",&sh[i].barcode);
        fscanf(ff," %s",sh[i].m_date);
        fscanf(ff," %s",sh[i].e_date);
        getc(ff);
        }

        fclose(ff);
        for(i=0;i<count2;i++)
        {
        if(i==j)
        {
        printf("\n%d.%s",i+1,sh[i].subitem);
        printf("\t\t%s",sh[i].brand);
        printf("\t\t%0.2f",sh[i].price);
        printf("\t\t%d",sh[i].barcode);
        printf("\t\t%s",sh[i].m_date);
        printf("\t\t%s",sh[i].e_date);


        sum2+=sh[i].price;
        }
        }
        for(i=0;i<count2;i++)
        {
        if(i==j)
        {
        fprintf(fsf,"\n%s",sh[i].subitem);
        fprintf(fsf,"\t\t%s",sh[i].brand);
        fprintf(fsf,"\t\t%0.2f",sh[i].price);
        fprintf(fsf,"\t\t%d",sh[i].barcode);
        fprintf(fsf,"\t\t%s",sh[i].m_date);
        fprintf(fsf,"\t\t%s",sh[i].e_date);
        }
        }
    }
    printf("\n\nTotal: %0.2f tk",sum2);
    fclose(fsf);

}
void take_input_k()
{
    printf("how many items :");
    scanf("%d",&c1);
    for(i=0;i<c1;i++)
    {
        count1++;
        printf("Name:");
        scanf("%s",sh[i].subitem);
        printf("Brand:");
        scanf("%s",sh[i].brand);
        printf("Color:");
        scanf("%s",sh[i].color);
        printf("price:");
        scanf(" %f",&sh[i].price);
        printf("Barcode:");
        scanf(" %d",&sh[i].barcode);
        printf("Material:");
        scanf(" %s",sh[i].material);
        printf("Manufacture date:");
        scanf(" %s",sh[i].m_date);
        printf("Expired date:");
        scanf("%s",sh[i].e_date);
    }
}

void print_to_file_k()
{
    for(i=0;i<c1;i++)
    {

        printf("\n%s",sh[i].subitem);
        printf("\t\t%s",sh[i].brand);
        printf("\t\t%s",sh[i].color);
        printf("\t\t%.2f",sh[i].price);
        printf("\t\t%d",sh[i].barcode);
        printf("\t\t%s",sh[i].material);
        printf("\t\t%s",sh[i].m_date);
        printf("\t\t%s",sh[i].e_date);
    }
    int kc1;
    fkc=fopen("fkc.txt","r");
    if(fkc!=NULL)
    {
        fscanf(fkc,"%d",&kc1);
    }
    else
    {
        kc1=0;
    }
    fkc=fopen("fkc.txt","w");
    fprintf(fkc,"%d",c1+kc1);
    fclose(fkc);
    fk=fopen("kitchen.txt","a");
    for(i=0;i<c1;i++)
    {
        fprintf(fk,"%s\t\t",sh[i].subitem);
        fprintf(fk,"%s\t\t",sh[i].brand);
        fprintf(fk,"%s\t\t",sh[i].color);
        fprintf(fk,"%0.2f\t\t",sh[i].price);
        fprintf(fk,"%d\t\t",sh[i].barcode);
        fprintf(fk,"%s\t\t",sh[i].material);
        fprintf(fk,"%s\t\t",sh[i].m_date);
        fprintf(fk,"%s\t\t",sh[i].e_date);


    }
    fclose(fk);
}
void read_from_file_k()
{
    fkc=fopen("fkc.txt","r");
    fscanf(fkc,"%d",&count1);
    fclose(fkc);
    fk=fopen("kitchen.txt","r");
    for(i=0;i<count1;i++)
    {
        fscanf(fk,"%s",sh[i].subitem);
        fscanf(fk,"%s",sh[i].brand);
        fscanf(fk,"%s",sh[i].color);
        fscanf(fk,"%f",&sh[i].price);
        fscanf(fk,"%d",&sh[i].barcode);
        fscanf(fk," %s",sh[i].material);
        fscanf(fk," %s",sh[i].m_date);
        fscanf(fk," %s",sh[i].e_date);
        getc(fk);
    }
    fclose(fk);
    for(i=0;i<count1;i++)
    {
        printf("\n%d.%s",i+1,sh[i].subitem);
        printf("\t\t%s",sh[i].brand);
        printf("\t\t%s",sh[i].color);
        printf("\t\t%0.2f",sh[i].price);
        printf("\t\t%d",sh[i].barcode);
        printf("\t\t%s",sh[i].material);
        printf("\t\t%s",sh[i].m_date);
        printf("\t\t%s",sh[i].e_date);
    }

}
void take_input_f()
{
    printf("how many items:");
    scanf("%d",&c2);
    for(i=0;i<c2;i++)
    {
        printf("Name:");
        scanf("%s",sh[i].subitem);
        printf("kg/gm/liter:");
        scanf("%s",sh[i].brand);
        printf("price:");
        scanf(" %f",&sh[i].price);
        printf("Barcode:");
        scanf(" %d",&sh[i].barcode);
        printf("Manufacture date:");
        scanf(" %s",sh[i].m_date);
        printf("Expired date:");
        scanf("  %s",sh[i].e_date);
    }
}
void print_to_file_f()
{
    for(i=0;i<c2;i++)
    {

        printf("\n%s",sh[i].subitem);
        printf("\t\t%s",sh[i].brand);
        printf("\t\t%.2f",sh[i].price);
        printf("\t\t%d",sh[i].barcode);
        printf("\t\t%s",sh[i].m_date);
        printf("\t\t%s",sh[i].e_date);
    }
    int fc1;
    ffc=fopen("ffc.txt","r");
    if(ffc!=NULL)
    {
        fscanf(ffc,"%d",&fc1);
    }
    else
    {
        fc1=0;
    }
    ffc=fopen("ffc.txt","w");
    fprintf(ffc,"%d",c2+fc1);
    fclose(ffc);
    ff=fopen("food.txt","a");
    for(i=0;i<c2;i++)
    {
        fprintf(ff,"\n%s\t\t",sh[i].subitem);
        fprintf(ff,"\n%s\t\t",sh[i].brand);
        fprintf(ff,"\n%0.2f\t\t",sh[i].price);
        fprintf(ff,"\n%d\t\t",sh[i].barcode);
        fprintf(ff,"\n%s\t\t",sh[i].m_date);
        fprintf(ff,"\n%s\t\t",sh[i].e_date);


    }
    fclose(ff);
}
void read_from_file_f()
{
    ffc=fopen("ffc.txt","r");
    fscanf(ffc,"%d",&count2);
    fclose(ffc);
    ff=fopen("food.txt","r");
    for(i=0;i<count2;i++)
    {
        fscanf(ff,"%s",sh[i].subitem);
        fscanf(ff,"%s",sh[i].brand);
        fscanf(ff,"%f",&sh[i].price);
        fscanf(ff,"%d",&sh[i].barcode);
        fscanf(ff," %s",sh[i].m_date);
        fscanf(ff," %s",sh[i].e_date);
        getc(ff);
    }
    fclose(ff);
    for(i=0;i<count2;i++)
    {
        printf("\n%d.%s",i+1,sh[i].subitem);
        printf("\t\t%s",sh[i].brand);
        printf("\t\t%0.2f",sh[i].price);
        printf("\t\t%d",sh[i].barcode);
        printf("\t\t%s",sh[i].m_date);
        printf("\t\t%s",sh[i].e_date);
    }

}
void sold_item_e()
{
    fsec=fopen("electric_count.txt","r");
    fscanf(fsec,"%d",&count);
    fclose(fsec);
    fse=fopen("electric_item.txt","r");
    for(i=0;i<count;i++)
    {
        fscanf(fse," %s",sh[i].subitem);
        fscanf(fse,"%s",sh[i].brand);
        fscanf(fse,"%s",sh[i].color);
        fscanf(fse,"%f",&sh[i].price);
        fscanf(fse,"%d",&sh[i].barcode);
        fscanf(fse," %s",sh[i].material);
        fscanf(fse," %s",sh[i].m_date);
        fscanf(fse," %s",sh[i].e_date);
        getc(fse);
    }
    fclose(fse);
    for(i=0;i<count;i++)
    {
        printf("\n%s",sh[i].subitem);
        printf("\t\t%s",sh[i].brand);
        printf("\t\t%s",sh[i].color);
        printf("\t\t%0.2f",sh[i].price);
        printf("\t\t%d",sh[i].barcode);
        printf("\t\t%s",sh[i].material);
        printf("\t\t%s",sh[i].m_date);
        printf("\t\t%s",sh[i].e_date);
    }

}
void sold_item_k()
{
    fskc=fopen("kitchen_count.txt","r");
    fscanf(fskc,"%d",&count1);
    fclose(fskc);
    fsk=fopen("kitchen_item.txt","r");
    for(i=0;i<count1;i++)
    {
        fscanf(fsk," %s",sh[i].subitem);
        fscanf(fsk,"%s",sh[i].brand);
        fscanf(fsk,"%s",sh[i].color);
        fscanf(fsk,"%f",&sh[i].price);
        fscanf(fsk,"%d",&sh[i].barcode);
        fscanf(fsk," %s",sh[i].material);
        fscanf(fsk," %s",sh[i].m_date);
        fscanf(fsk," %s",sh[i].e_date);
        getc(fsk);
    }
    fclose(fsk);
    for(i=0;i<count1;i++)
    {
        printf("\n%s",sh[i].subitem);
        printf("\t\t%s",sh[i].brand);
        printf("\t\t%s",sh[i].color);
        printf("\t\t%0.2f",sh[i].price);
        printf("\t\t%d",sh[i].barcode);
        printf("\t\t%s",sh[i].material);
        printf("\t\t%s",sh[i].m_date);
        printf("\t\t%s",sh[i].e_date);
    }

}
void sold_item_f()
{
    fsfc=fopen("food_count.txt","r");
    fscanf(fsfc,"%d",&count2);
    fclose(fsfc);
    fsf=fopen("food_items.txt","r");
    for(i=0;i<count2;i++)
    {
        fscanf(fsf, "%s",sh[i].subitem);
        fscanf(fsf,"%s",sh[i].brand);
        fscanf(fsf,"%f",&sh[i].price);
        fscanf(fsf,"%d",&sh[i].barcode);
        fscanf(fsf," %s",sh[i].m_date);
        fscanf(fsf," %s",sh[i].e_date);

    }
    fclose(fsf);
    for(i=0;i<count2;i++)
    {
        printf("\n%s",sh[i].subitem);
        printf("\t\t%s",sh[i].brand);
        printf("\t\t%0.2f",sh[i].price);
        printf("\t\t%d",sh[i].barcode);
        printf("\t\t%s",sh[i].m_date);
        printf("\t\t%s",sh[i].e_date);
    }
}
