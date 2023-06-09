﻿# inventory_project_oop
This program is a Retail Inventory Management System. Here are the features of this program:

1) Add product with price: This feature allows you to add a product to the inventory with a specified name, quantity, and price. The program prompts you to enter the product name, quantity, and price, and then creates a new instance of the "ProductWithPrice" class with the provided information. The product is then added to the inventory.

2) Add product with weight: This feature allows you to add a product to the inventory with a specified name, quantity, and weight. The program prompts you to enter the product name, quantity, and weight in kilograms. It creates a new instance of the "ProductWithWeight" class with the provided information and adds the product to the inventory.

3) Display inventory: This feature displays the details of all products in the inventory. It iterates over the products vector and calls the "displayDetails" function for each product, which outputs the type, name, quantity, and additional details (price or weight) of the product.

4) Save inventory to file: This feature allows you to save the current inventory to a file. It prompts you to enter a filename and then opens the file for writing. The program writes the details of each product to the file, including the type, name, quantity, and additional details (price or weight). Each product's details are written on separate lines, and an empty line is added between products. After writing all the products, the file is closed.

5) Load inventory from file: This feature allows you to load inventory data from a previously saved file. It prompts you to enter the filename of the file to load. The program opens the file for reading and reads the product details from the file line by line. It creates instances of the appropriate product classes (ProductWithPrice or ProductWithWeight) based on the type of product read from the file. The program then adds these products to the inventory. Each product's details in the file should be structured as per the save format.

6) Exit: This feature allows you to exit the program.

The program utilizes abstraction, encapsulation, inheritance, polymorphism & file handling to manage different types of products (products with price and products with weight) using a common base class (Product). The Inventory class maintains a vector of pointers to Product objects, allowing for dynamic polymorphism and storage of different types of products in a single container.
