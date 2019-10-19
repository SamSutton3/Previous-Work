from sqlite3 import *
from datetime import datetime, date

class database():
    def __init__(self):
        self.db_file = "ChipInn.db"

    def open_conn(self):
        self.db_conn = connect(self.db_file)
        self.cur = self.db_conn.cursor()

    def disconnect(self):
        self.db_conn.close()

    def create_table(self,tbl_name):
        sql = ""
        if tbl_name == "Category":
            sql = "CREATE TABLE Categories (CategoryID INTEGER NOT NULL PRIMARY KEY, Name TEXT NOT NULL UNIQUE);"
        elif tbl_name == "Products":
            sql = "CREATE TABLE Product (ProductID INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT, Name TEXT NOT NULL UNIQUE,Price REAL NOT NULL,Stock INTEGER);"
        elif tbl_name == "Products_Category1":
            sql = "CREATE TABLE Product_Cat (Product_Cat_ID INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT, ProductID INTEGER, CategoryID INTEGER, FOREIGN KEY(ProductID) REFERENCES Product(ProductID),FOREIGN KEY(CategoryID) REFERENCES Category(CategoryID));"
        elif tbl_name == "Orders":
            sql = "CREATE TABLE Orders(OrderID INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,DateOfOrder DATE, TotalPrice REAL NOT NULL);"
        elif tbl_name == "OrderItems1":
            sql = "CREATE TABLE OrderItems (OrderItemId INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT, OrderID INTEGER, ProductID INTEGER, Price_Sold_At REAL, Qty INTEGER DEFAULT 1, FOREIGN KEY(ProductID) REFERENCES Product(ProductID), FOREIGN KEY(OrderID) REFERENCES Orders(OrderID));"
        elif tbl_name == "Users2":
            sql = "CREATE TABLE Users (UserID INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT, Username TEXT NOT NULL UNIQUE, Password NOT NULL);"
        elif tbl_name == "Permissions":
            sql = "CREATE TABLE Permissions (PermissionsID INTEGER NOT NULL PRIMARY KEY, PermissionLevel TEXT NOT NULL UNIQUE);"
        elif tbl_name == "User_Permissions":
            sql = "CREATE TABLE User_Permissions (User_Permissions_ID INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT, PermissionsID INTEGER, UserID INTEGER, FOREIGN KEY(PermissionsID) REFERENCES Permissions(PermissionsID),FOREIGN KEY(UserID) REFERENCES Users(UserID));"
        elif tbl_name == "Suppliers":
            sql = "CREATE TABLE Suppliers (SupplierID INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT, SupplierEmail NOT NULL, SupplierName TEXT)"
        elif tbl_name == "Supplier_Category":
            sql = "CREATE TABLE Supplier_Category (SupplierCategoryID INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT, SupplierID INTEGER, CategoryID INTEGER, FOREIGN KEY(SupplierID) REFERENCES Suppliers(SupplierID), FOREIGN KEY(CategoryID) REFERENCES Category(CategoryID))"
        elif tbl_name == "Stock_ReOrders1":
            sql = "CREATE TABLE ReOrders (ReOrderID INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT, SupplierName Text, ProductID INTEGER, Quantity INTEGER NOT NULL, Completed TEXT NOT NULL, FOREIGN KEY(ProductID) REFERENCES Product(ProductID), FOREIGN KEY(SupplierName) REFERENCES Suppliers(SupplierName))"
        try:
            self.open_conn()
            self.cur.execute(sql)
            self.db_conn.commit()
            self.disconnect()
        except:
            pass

    def insert_suppliers_category(self):
        self.show_all_categories()
        inputCID = int(input("Select a Category you would like to assign (using the ID)> "))
        self.open_conn()
        self.cur.execute("SELECT Name FROM Categories WHERE CategoryID=?",(inputCID))
        categoryName = self.cur.fetchone()
        self.show_all_suppliers()
        inputSID = int(input("Select a Supplier you would like to assign to the Category "+str(categoryName)+"(using the ID)> "))
        self.open_conn()
        self.cur.execute("INSERT INTO Supplier_Category (SupplierID,CategoryID) VALUES (?,?)",(inputSID, inputCID))
        self.db_conn.commit()
        self.disconnect()

    def insert_suppliers(self):
        self.show_all_suppliers()
        self.open_conn()
        inputSN = input ("Supplier Name> ")
        inputSE = input ("Supplier Email> ")
        self.cur.execute("INSERT INTO Suppliers (SupplierEmail,SupplierName) VALUES (?,?)",(inputSE, inputSN))
        self.db_conn.commit()
        self.disconnect()

    def show_all_suppliers(self):
        self.open_conn()
        self.cur.execute('SELECT * FROM Suppliers')
        showall = self.cur.fetchall()
        print(showall)
        self.disconnect()

    def show_all_suppliers_categories(self):
        self.open_conn()
        self.cur.execute('SELECT * FROM Supplier_Category')
        showall = self.cur.fetchall()
        print(showall)
        self.disconnect()

    def insert_product(self):
        self.show_all_products()
        self.open_conn()
        inputPN = input ("Product Name> ")
        inputPC = input ("Product Price> ")
        inputPS = int(input ("First Stock Count> "))
        self.cur.execute("INSERT INTO Product (Name,Price,Stock) VALUES (?,?,?)",(inputPN, inputPC, inputPS))
        self.db_conn.commit()
        self.assign_product()
        self.open_conn()
        self.db_conn.commit()
        self.disconnect()

    def insert_category(self):
        self.show_all_categories()
        self.open_conn()
        inputCID = int(input("CategoryID >"))
        inputCN = input ("Category Name> ")
        self.cur.execute("INSERT INTO Categories (CategoryID,Name) VALUES (?,?)",(inputCID,inputCN))
        self.db_conn.commit()
        self.disconnect()

    def insert_permission_group(self):
        self.show_all_groups()
        self.open_conn()
        inputPID = int(input("PermissionID > "))
        inputPGN = input("Permission Group Name > ")
        self.cur.execute("INSERT INTO Permissions (PermissionsID,PermissionLevel) VALUES (?,?)", (inputPID,inputPGN))
        self.db_conn.commit()
        self.disconnect()

    def add_user (self):
        self.show_all_users()
        self.open_conn()
        inputUN = input("Username> ")
        inputPW = input("Password> ")
        self.cur.execute("INSERT INTO Users (Username,Password) VALUES (?,?)",(inputUN,inputPW))
        self.db_conn.commit()
        self.disconnect()

    def assign_user(self):
        self.show_all_users()
        inputUID = int(input("Select a User using the UserID> "))
        self.show_all_groups()
        self.open_conn()
        inputPID = input("Select a Permission Group using the PermissionsID>  ")
        self.cur.execute("INSERT INTO User_Permissions (UserID,PermissionsID) VALUES (?,?)",(inputUID,inputPID))
        self.db_conn.commit()
        self.disconnect()

    def assign_product(self):
        self.show_all_products()
        inputPID = int(input("Select a Product using the ProductID> "))
        self.show_all_categories()
        self.open_conn()
        inputCID = int(input("Select a Category using the CategoryID> "))
        self.cur.execute("INSERT INTO Product_Cat (CategoryID,ProductID) VALUES (?,?)",(inputCID,inputPID))
        self.db_conn.commit()
        self.show_all_permission_groups()
        self.disconnect()

    def show_all_products(self):
        self.open_conn()
        self.cur.execute('SELECT * FROM Product where Stock > 0')
        showall = self.cur.fetchall()
        print(showall)
        self.disconnect()

    def show_all_permission_groups(self):
        self.open_conn()
        self.cur.execute('SELECT * FROM User_Permissions')
        showall = self.cur.fetchall()
        print(showall)
        self.disconnect()

    def show_all_groups(self):
        self.open_conn()
        self.cur.execute('SELECT * FROM Permissions')
        showall = self.cur.fetchall()
        print(showall)
        self.disconnect()

    def show_all_productsCat(self):
        self.show_all_categories()
        self.open_conn()
        categorySelect = int(input("Please enter the Category ID> "))
        self.cur.execute("SELECT ProductID from Product_Cat where CategoryID=?", (categorySelect,))
        showall = self.cur.fetchall()
        for loop in range (0,len(showall)):
            value = showall[loop]
            self.cur.execute("SELECT * FROM Product where Stock > 0 and ProductID=?", (value))
            showall0 = self.cur.fetchall()
            print(showall0)
        self.disconnect()

    def show_all_categories(self):
        self.open_conn()
        self.cur.execute('SELECT * FROM Categories')
        showall = self.cur.fetchall()
        print(showall)
        self.disconnect()

    def show_all_users(self):
        self.open_conn()
        self.cur.execute('SELECT UserID,Username FROM Users')
        showall = self.cur.fetchall()
        print(showall)
        self.disconnect()

    def edit_product_selected(self,editID):
        self.open_conn()
        self.cur.execute("SELECT ProductID,Name,Price from Product where ProductID=?",(editID,))
        showone = self.cur.fetchone()
        print ("Product: "+str(showone))

    def edit_product(self):
        self.open_conn()
        self.cur.execute('SELECT * FROM Product')
        showall = self.cur.fetchall()
        print(showall)
        editID = int(input("Please enter the product ID of the product you`d like to edit> "))
        self.edit_product_selected(editID)
        inputPN = input("Please enter the new name: ")
        inputPP = input("Please enter the new price: ")
        self.cur.execute("UPDATE Product SET Name =?, Price =? WHERE ProductID =?", (inputPN, inputPP,editID))
        self.db_conn.commit()
        self.edit_product_selected(editID)

    def edit_user_selected(self,editID):
        self.open_conn()
        self.cur.execute("SELECT UserID,Username from Users where UserID=?",(editID,))
        showone = self.cur.fetchone()
        print ("User Selected: "+str(showone))
        self.security_user(editID)

    def security_user(self,editID):
        self.open_conn()
        self.cur.execute("SELECT Password from Users where UserID=?",(editID,))
        passwordForUser = self.cur.fetchone()
        passwordForUser1 = passwordForUser[0]
        passwordCheck = input("To check you can edit this user please enter the password> ")
        if passwordCheck == passwordForUser1:
            self.editUserContinue(editID)
        else:
            print("Incorrect Password")
            quit()

    def editUserContinue(self,editID):
        self.open_conn()
        inputUN = input("Please enter the new Username: ")
        inputPW = input("Please enter the Password: ")
        self.cur.execute("UPDATE Users SET Username =?, Password =? WHERE UserID =?", (inputUN, inputPW,editID))
        self.db_conn.commit()
        self.cur.execute("SELECT * from Users where UserID=?",(editID,))
        showEditUser = self.cur.fetchone()
        print(showEditUser)
        self.disconnect()

    def edit_user(self):
        self.show_all_users()
        editID = input ("Please enter the UserID of the User you`d like to edit> ")
        self.edit_user_selected(editID)

