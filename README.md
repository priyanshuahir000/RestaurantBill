# Restaurant Billing System

This C project, developed during my first semester in college, is a simple restaurant billing system. It allows users to create invoices, view all previous invoices, search for invoices by customer name, and save the invoices to a file.

## Features

- **Create Invoice**: Users can create invoices by entering customer details, items purchased, quantity, and unit price. The invoice includes the date, customer name, items purchased, quantity, total price, discounts, and grand total.
- **Show All Invoices**: Users can view all previous invoices stored in the file.
- **Search Invoice**: Users can search for a specific invoice by entering the customer's name.
- **Save Invoice**: Users have the option to save the invoice to a file.

## How to Run

To run the program, compile the source code using any C compiler. For example, if you're using GCC, you can compile the program with the following command:

```bash 
gcc -o restaurant_billing restaurant_billing.c
```

After compilation, execute the program:
```bash
./restaurant_billing
```

# Usage

Follow the on-screen prompts to navigate through the menu options:

1. **Create Invoice**: Enter customer details, items purchased, quantity, and unit price.
2. **Show All Invoices**: View all previous invoices.
3. **Search Invoice**: Enter the customer's name to search for a specific invoice.
4. **Exit**: Exit the program.

# File Management

The program stores the invoices in a file named `Restaurant.dat`. Make sure to handle file permissions and ensure that the file is accessible to the program.

Feel free to explore and modify the source code to enhance the functionality or customize it according to your requirements.
