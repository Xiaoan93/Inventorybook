#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

typedef struct books
{
    long long ISBN;
    char Title[50];
    char Author[50];
    char Publisher[50];
    char Genre[50];
    int Year_of_Publication;
    int Amount_in_Stock;
    float Selling_Price;
} books;

books books_array[500];
int k=0;

void pre_populate_inventory();
void populate_inventory();
void print_books(int);
void display_books();
int search();
void process_transaction();
void purchase_book();
void return_book();
int search_ISBN();
void clear_record();
void delete_record();

int main()
{   
    //books b1, b2, b3, b4, b5;
    int choice;
    int i;
    pre_populate_inventory();
    while(1){
        system("cls");
        do
        {   printf("\n");
            printf("Welcome to the Book Store! \n");
            printf("******************************\n");
            printf("1. Populate_inventory \n");
            printf("2. Search \n");
            printf("3. Process_transaction \n");
            printf("4. Delete_record \n");
            printf("5. Display_books \n");
            printf("6. Exit \n");
            printf("******************************\n");
            printf("Please choose the menu:\n");
            scanf("%d", &choice);
        } while (choice < 1 || choice > 6);
        switch (choice){
        case 1:
            populate_inventory();
            break;
        case 2:
            search();
            break;
        case 3:
            process_transaction();
            break;
        case 4:
            delete_record();
            break;
        case 5:
            display_books();
            break;
        case 6:
            printf("Thank you for using Inventory System ~");
            exit(0);
        }
        getch();
    }
return 0;
}

void pre_populate_inventory()
{
    books b1;
    books_array[0].ISBN = 9783442178582;
    strcpy(books_array[0].Title, "Atomic Habits");
    strcpy(books_array[0].Author, "James Clear");
    strcpy(books_array[0].Publisher, "Penguin Publishing Group");
    strcpy(books_array[0].Genre, "Self-help book");
    books_array[0].Year_of_Publication = 2018;
    books_array[0].Amount_in_Stock = 50;
    books_array[0].Selling_Price = 17.45;

    books b2;
    books_array[1].ISBN = 9781543626612;
    strcpy(books_array[1].Title, "Rich Dad Poor Dad");
    strcpy(books_array[1].Author, "Robert Kiyosaki & Sharon L. Lechter");
    strcpy(books_array[1].Publisher, "Warner Books");
    strcpy(books_array[1].Genre, "Personal finance");
    books_array[1].Year_of_Publication = 1997;
    books_array[1].Amount_in_Stock = 50;
    books_array[1].Selling_Price = 18;

    books b3;
    books_array[2].ISBN = 9781501124020;
    strcpy(books_array[2].Title, "Principles");
    strcpy(books_array[2].Author, "Ray Dalio");
    strcpy(books_array[2].Publisher, "Simon & Schuster");
    strcpy(books_array[2].Genre, "Biography");
    books_array[2].Year_of_Publication = 2017;
    books_array[2].Amount_in_Stock = 50;
    books_array[2].Selling_Price = 33.68;
 
    books b4;
    books_array[3].ISBN = 9781529326864;
    strcpy(books_array[3].Title, "The American Trap");
    strcpy(books_array[3].Author, "Frederic Pierucci");
    strcpy(books_array[3].Publisher, "Hodder & Stoughton");
    strcpy(books_array[3].Genre, "Biography");
    books_array[3].Year_of_Publication = 2019;
    books_array[3].Amount_in_Stock = 50;
    books_array[3].Selling_Price = 15.86;

    //books b5;
    books_array[4].ISBN = 9780957111653;
    strcpy(books_array[4].Title, "A Short History of the World");
    strcpy(books_array[4].Author, "Christopher Lascelles");
    strcpy(books_array[4].Publisher, "Cassell & Company & The Macmillan Company");
    strcpy(books_array[4].Genre, "Fiction");
    books_array[4].Year_of_Publication = 1922;
    books_array[4].Amount_in_Stock = 50;
    books_array[4].Selling_Price = 23;
    k=5;
}

void populate_inventory(){    
    int num_of_books;
    char ans;
    
    printf("How many books do you want to enter? \n");
    scanf("%d", &num_of_books);   
    
    for (int i=0; i < num_of_books; i++){
        fflush(stdin);
        printf("Enter book ISBN: \n");
        scanf("%lld", &books_array[k].ISBN);
        fflush(stdin);
        printf("Enter book title: \n");
        scanf("%[^\n]%*c", books_array[k].Title); //makes no space.
        fflush(stdin);
        printf("Enter book author: \n");
        scanf("%[^\n]%*c", books_array[k].Author);
        fflush(stdin);
        printf("Enter book publisher: \n");
        scanf("%[^\n]%*c", books_array[k].Publisher);
        fflush(stdin);
        printf("Enter book genre: \n");
        scanf("%[^\n]%*c", books_array[k].Genre);
        fflush(stdin);
        printf("Enter book year of publication: \n");
        scanf("%d", &books_array[k].Year_of_Publication);
        fflush(stdin);
        printf("Enter book amount in stock: \n");
        scanf("%d", &books_array[k].Amount_in_Stock);
        fflush(stdin);
        printf("Enter book selling price: \n");
        scanf("%f", &books_array[k].Selling_Price);
        k++;
    }
    display_books();   
}

int search(){
    char keyword[50];
    char ans;
    fflush(stdin);
    printf("Enter the keyword that you want to search: \n");
    scanf("%[^\n]%*c", keyword);
    int count=0;  
    for (int i = 0; i < k; i++){
        if(strstr(books_array[i].Title, keyword) !=NULL){   
            print_books(i);
            count++;        
            //return i;
        }
        else if (strstr(books_array[i].Author, keyword)!=NULL){
            print_books(i);
            count++;
            //return i;
        }
        else if (strstr(books_array[i].Publisher, keyword)!=NULL){
            print_books(i);
            count++;
            //return i;
        }
        else if(strstr(books_array[i].Genre, keyword)!=NULL){
            print_books(i);
            count++; 
            //return i;
        }
    } 
    if (count>0)
        return count; 
    printf("No match\n");
    return -1;  
}

void print_books(int x){
        printf("\n");
        printf("*************************************** \n");
        printf("ISBN: %lld\n", books_array[x].ISBN);
        printf("Title: %s\n", books_array[x].Title);
        printf("Author: %s\n", books_array[x].Author);
        printf("Publihser: %s\n", books_array[x].Publisher);
        printf("Genre: %s\n", books_array[x].Genre);
        printf("Year of Publication: %d\n", books_array[x].Year_of_Publication);
        printf("Amount in Stock: %d\n", books_array[x].Amount_in_Stock);
        printf("Selling Price: %.2f\n", books_array[x].Selling_Price);
        printf("*************************************** \n");
        printf("\n");
}

void display_books(){
    for (int i = 0; i < k; i++)
    {   
        print_books(i);
    }
}

void process_transaction(){
    int choice;
    do
    {
        printf("Enter the option of purchase or return books: \n");
        printf("1. Purchase Books. \n");
        printf("2. Return Books. \n");
        scanf("%d", &choice);
    } while (choice<1||choice>2);
    switch (choice)
    {
    case 1:
        purchase_book();
        break;
    case 2:
        return_book();
        break;
    } 
}

void purchase_book(){
    char Title[50]; 
    int num_books;
    long long ISBN;
    int index= search_ISBN();
    if(index!=-1){ 
        do{
            printf("How many books do you want to purchase? max %d\n", books_array[index].Amount_in_Stock);
            scanf("%d", &num_books);
            if (num_books > books_array[index].Amount_in_Stock)
            {
                printf("Only %d books is available now\n", books_array[index].Amount_in_Stock);
            }
            
        } while (num_books > books_array[index].Amount_in_Stock);

        if(books_array[index].Amount_in_Stock>=num_books ){
            books_array[index].Amount_in_Stock=books_array[index].Amount_in_Stock-num_books;
            print_books(index);
        }
    }
    else{
        printf("Book not found to purchase! \n");
    }
}


void return_book(){
    char Title[50];
    int num_books;
    int ISBN_index = search_ISBN();
    if(ISBN_index==-1){
        printf("Book not found to return. \n");
    }
    else if(ISBN_index!=-1){
        printf("How many books do you want to return? \n");
        scanf("%d", &num_books);
        books_array[ISBN_index].Amount_in_Stock=books_array[ISBN_index].Amount_in_Stock+num_books;
        print_books(ISBN_index);
    }
}

int search_ISBN(){
    long long ISBN;
    fflush(stdin);
    printf("Enter the ISBN you want to search: \n");
    scanf("%lld", &ISBN);
    for (int i = 0; i < k; i++){
        if(books_array[i].ISBN == ISBN){
            print_books(i);
            return i;
        }
    }
    return -1;   
}
void clear_record(){
    books_array[k-1].ISBN = 0;
    strcpy(books_array[k-1].Author, " ");
    strcpy(books_array[k-1].Title, " ");
    strcpy(books_array[k-1].Publisher, " ");
    strcpy(books_array[k-1].Genre, " ");
    books_array[k-1].Amount_in_Stock = 0;
    books_array[k-1].Year_of_Publication = 0;
    books_array[k-1].Selling_Price = 0;
    k--;
    printf("The record has been removed\n");
}

void delete_record(){
    int index;
    index=search_ISBN();
    if(index==-1){
            printf("Book not found. \n");
    }
    else
    {
        for (int i = index; i <= k-2; i++){
            books_array[i]=books_array[i+1];
        }   
        clear_record();
    }    
    display_books();
}
