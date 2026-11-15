# Inventory and Billing Management System

A menu-driven Inventory and Billing Management System developed in **C**
using **structures, arrays, functions, and file handling**. The program
allows users to manage product details, update stock, generate customer
bills, and store product and billing records in text files.

## Features

-   Add new products with an ID, name, price, and available quantity.
-   Display all products in the inventory.
-   Search for a product using its ID.
-   Update the stock quantity of an existing product.
-   Generate a customer bill using a product ID and purchase quantity.
-   Calculate the product amount and final bill amount.
-   Automatically reduce stock after a successful purchase.
-   Save inventory records in `products.txt`.
-   Save customer billing records in `billing.txt`.
-   Load previously saved product records when the program starts.
-   View the records stored in both text files.

## Technologies and Concepts

-   **Language:** C
-   **Compiler:** GCC
-   **Concepts used:**
    -   Structures
    -   Arrays of structures
    -   Functions
    -   Conditional statements
    -   Loops
    -   Switch-case
    -   File handling
    -   File operations: `fopen()`, `fscanf()`, `fprintf()`, and
        `fclose()`

## Project Structure

After compiling and running the program, the folder will contain:

``` text
Inventory_Billing_System/
├── inventory.c
├── inventory.exe       # Generated after compilation on Windows
├── products.txt        # Created when product data is saved
└── billing.txt         # Created when a successful bill is recorded
```

The two text files are created automatically by the program when
required. You do not need to create them manually.

## Requirements

-   A C compiler such as GCC.
-   A terminal or code editor such as Visual Studio Code.

Check whether GCC is installed:

``` bash
gcc --version
```

## How to Compile and Run

### Windows (VS Code terminal / PowerShell)

1.  Open the project folder in VS Code.

2.  Open the integrated terminal.

3.  Compile the source file:

    ``` bash
    gcc inventory.c -o inventory.exe
    ```

4.  Run the program:

    ``` powershell
    .\inventory.exe
    ```

### Linux / macOS

Compile:

``` bash
gcc inventory.c -o inventory
```

Run:

``` bash
./inventory
```

## Main Menu

When the program runs, it displays the following menu:

``` text
INVENTORY AND BILLING MANAGEMENT SYSTEM

1. Add Product
2. Display Products
3. Search Product
4. Update Stock
5. Generate Bill
6. Display Product Records
7. Display Billing Records
8. Exit

Enter your choice:
```

Select an option by entering its corresponding number.

## File Handling

The program uses two text files to store data.

### 1. `products.txt`

Stores product information:

-   Product ID
-   Product Name
-   Price
-   Available Quantity
-   Total Stock Amount

The program uses **write mode (`"w"`)** to save the current inventory
and **read mode (`"r"`)** to load existing product records when it
starts.

Example record:

``` text
301 Notebook 50.00 100 5000.00
```

The total stock amount is calculated as:

``` text
Price × Available Quantity
```

### 2. `billing.txt`

Stores successful customer purchase records:

-   Product ID
-   Product Name
-   Price
-   Purchase Quantity
-   Bill Amount

The program uses **append mode (`"a"`)** so that new billing records are
added without deleting previous transactions.

Example record:

``` text
301 Notebook 50.00 3 150.00
```

## Sample Billing Calculation

Suppose the inventory contains:

  Product Detail             Value
  -------------------- -----------
  Product ID                   301
  Product Name            Notebook
  Price                  Rs. 50.00
  Available Quantity           100

A customer purchases 3 notebooks.

**Bill amount:**

``` text
50.00 × 3 = Rs. 150.00
```

**Remaining stock:**

``` text
100 - 3 = 97
```

The updated stock is saved in `products.txt`, and the purchase is
recorded in `billing.txt`.

## Important Notes and Limitations

-   Product names must be single words because the program uses `%s` for
    input and whitespace-separated file records.
-   Each bill currently supports one product per transaction.
-   The program supports up to 100 products.
-   Stock updates replace the existing quantity with the newly entered
    quantity.
-   Run the executable from the project folder so that the text files
    are created and accessed in the expected location.
-   Enter valid numeric input when prompted.

## Learning Objectives

This project demonstrates how structures and file handling can be used
together to build a basic inventory and billing application. It provides
practical experience with storing structured records, searching and
updating data, performing calculations, and maintaining information
between program executions.

## Author

Developed as a C programming project for the **Inventory and Billing
Management System** assignment.
