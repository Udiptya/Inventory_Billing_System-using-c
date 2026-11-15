
#include <stdio.h>

struct Product
{
    int id;
    char name[50];
    float price;
    int quantity;
    float totalAmount;
};

struct Product p[100];
int n = 0;

// Load products from file
void loadProducts()
{
    FILE *fp;
    fp = fopen("products.txt", "r");

    if (fp == NULL)
        return;

    n = 0;

    while (fscanf(fp, "%d %s %f %d %f",
           &p[n].id, p[n].name, &p[n].price,
           &p[n].quantity, &p[n].totalAmount) == 5)
    {
        n++;

        if (n == 100)
            break;
    }

    fclose(fp);
}

// Save products to file
void saveProducts()
{
    FILE *fp;
    int i;

    fp = fopen("products.txt", "w");

    if (fp == NULL)
    {
        printf("File opening error!\n");
        return;
    }

    for (i = 0; i < n; i++)
    {
        p[i].totalAmount = p[i].price * p[i].quantity;

        fprintf(fp, "%d %s %.2f %d %.2f\n",
                p[i].id, p[i].name, p[i].price,
                p[i].quantity, p[i].totalAmount);
    }

    fclose(fp);
}

// Add product
void addProduct()
{
    int i, id;

    if (n == 100)
    {
        printf("Inventory is full!\n");
        return;
    }

    printf("Enter Product ID: ");
    scanf("%d", &id);

    for (i = 0; i < n; i++)
    {
        if (p[i].id == id)
        {
            printf("Product ID already exists!\n");
            return;
        }
    }

    p[n].id = id;

    printf("Enter Product Name: ");
    scanf("%49s", p[n].name);

    printf("Enter Price: ");
    scanf("%f", &p[n].price);

    printf("Enter Available Quantity: ");
    scanf("%d", &p[n].quantity);

    if (id <= 0 || p[n].price <= 0 || p[n].quantity < 0)
    {
        printf("Invalid product details!\n");
        return;
    }

    p[n].totalAmount = p[n].price * p[n].quantity;

    n++;

    saveProducts();

    printf("Product added successfully!\n");
}

// Display products
void displayProducts()
{
    int i;

    printf("\nPRODUCT INVENTORY\n");
    printf("ID\tName\tPrice\tQuantity\tTotal\n");

    for (i = 0; i < n; i++)
    {
        printf("%d\t%s\t%.2f\t%d\t\t%.2f\n",
               p[i].id, p[i].name, p[i].price,
               p[i].quantity,
               p[i].price * p[i].quantity);
    }
}

// Search product
void searchProduct()
{
    int id, i, found = 0;

    printf("Enter Product ID: ");
    scanf("%d", &id);

    for (i = 0; i < n; i++)
    {
        if (p[i].id == id)
        {
            printf("\nProduct ID: %d", p[i].id);
            printf("\nProduct Name: %s", p[i].name);
            printf("\nPrice: %.2f", p[i].price);
            printf("\nQuantity: %d", p[i].quantity);
            found = 1;
            break;
        }
    }

    if (found == 0)
        printf("Product not found!\n");
}

// Update stock
void updateStock()
{
    int id, i, found = 0, qty;

    printf("Enter Product ID: ");
    scanf("%d", &id);

    for (i = 0; i < n; i++)
    {
        if (p[i].id == id)
        {
            printf("Current Quantity: %d\n", p[i].quantity);

            printf("Enter New Quantity: ");
            scanf("%d", &qty);

            if (qty < 0)
            {
                printf("Invalid quantity!\n");
                return;
            }

            p[i].quantity = qty;
            saveProducts();

            printf("Stock updated successfully!\n");
            found = 1;
            break;
        }
    }

    if (found == 0)
        printf("Product not found!\n");
}

// Generate bill
void generateBill()
{
    int id, qty, i, found = 0;
    float amount;

    printf("Enter Product ID: ");
    scanf("%d", &id);

    for (i = 0; i < n; i++)
    {
        if (p[i].id == id)
        {
            found = 1;

            printf("Enter Purchase Quantity: ");
            scanf("%d", &qty);

            if (qty <= 0)
            {
                printf("Invalid quantity!\n");
                return;
            }

            if (qty > p[i].quantity)
            {
                printf("Insufficient stock!\n");
                return;
            }

            amount = p[i].price * qty;

            printf("\nCUSTOMER BILL\n");
            printf("Product ID: %d\n", p[i].id);
            printf("Product Name: %s\n", p[i].name);
            printf("Price: %.2f\n", p[i].price);
            printf("Quantity: %d\n", qty);
            printf("Amount: %.2f\n", amount);

            printf("Final Bill Amount: Rs. %.2f\n", amount);

            p[i].quantity = p[i].quantity - qty;

            saveProducts();

            FILE *fp;
            fp = fopen("billing.txt", "a");

            if (fp == NULL)
            {
                printf("Billing file error!\n");
                return;
            }

            fprintf(fp, "%d %s %.2f %d %.2f\n",
                    p[i].id, p[i].name, p[i].price,
                    qty, amount);

            fclose(fp);

            printf("Remaining Stock: %d\n", p[i].quantity);
            printf("Bill saved successfully!\n");

            break;
        }
    }

    if (found == 0)
        printf("Product not found!\n");
}

// Display stored product records
void displayProductRecords()
{
    FILE *fp;
    int id, qty;
    float price, total;
    char name[50];

    fp = fopen("products.txt", "r");

    if (fp == NULL)
    {
        printf("No product records found!\n");
        return;
    }

    printf("\nSTORED PRODUCT RECORDS\n");

    while (fscanf(fp, "%d %s %f %d %f",
           &id, name, &price, &qty, &total) == 5)
    {
        printf("%d %s %.2f %d %.2f\n",
               id, name, price, qty, total);
    }

    fclose(fp);
}

// Display stored billing records
void displayBillingRecords()
{
    FILE *fp;
    int id, qty;
    float price, amount;
    char name[50];

    fp = fopen("billing.txt", "r");

    if (fp == NULL)
    {
        printf("No billing records found!\n");
        return;
    }

    printf("\nSTORED BILLING RECORDS\n");

    while (fscanf(fp, "%d %s %f %d %f",
           &id, name, &price, &qty, &amount) == 5)
    {
        printf("%d %s %.2f %d %.2f\n",
               id, name, price, qty, amount);
    }

    fclose(fp);
}

// Main function
int main()
{
    int choice;

    loadProducts();

    do
    {
        printf("\n\nINVENTORY AND BILLING MANAGEMENT SYSTEM\n");
        printf("1. Add Product\n");
        printf("2. Display Products\n");
        printf("3. Search Product\n");
        printf("4. Update Stock\n");
        printf("5. Generate Bill\n");
        printf("6. Display Product Records\n");
        printf("7. Display Billing Records\n");
        printf("8. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addProduct();
                break;

            case 2:
                displayProducts();
                break;

            case 3:
                searchProduct();
                break;

            case 4:
                updateStock();
                break;

            case 5:
                generateBill();
                break;

            case 6:
                displayProductRecords();
                break;

            case 7:
                displayBillingRecords();
                break;

            case 8:
                printf("Thank you!\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 8);

    return 0;
}
 