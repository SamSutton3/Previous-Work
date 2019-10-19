from DatabaseSetup import database
from datetime import datetime, timedelta

class ReOrdering():
    def __init__(self):
        self.db = database()

    def insertToStockReOrders(self,stockProductID,amountRequired):
        CategoryID = self.findCategoryID(stockProductID)
        SupplierID = self.findSupplierID(CategoryID)
        supplierName = self.findSupplierName(SupplierID)
        completedField = "N"
        self.db.cur.execute("INSERT INTO ReOrders (ProductID,Quantity,SupplierName,Completed) VALUES (?,?,?,?)",(stockProductID, amountRequired, supplierName, completedField))
        self.db.db_conn.commit()
        self.db.disconnect()

    def findSupplierName(self, SupplierID):
        self.db.open_conn()
        self.db.cur.execute("SELECT SupplierName FROM Suppliers WHERE SupplierID=?", (SupplierID,))
        fetchName = self.db.cur.fetchone()
        supplierName = fetchName[0]
        return (supplierName)

    def findCategoryID(self,stockProductID):
        self.db.open_conn()
        self.db.cur.execute("SELECT CategoryID FROM Product_Cat WHERE ProductID=?",(stockProductID,))
        fetchCategoryID = self.db.cur.fetchone()
        CategoryID = fetchCategoryID[0]
        return(CategoryID)

    def findSupplierID(self,CategoryID):
        self.db.open_conn()
        self.db.cur.execute("SELECT SupplierID FROM Supplier_Category WHERE CategoryID=?", (CategoryID,))
        fetchSupplierID = self.db.cur.fetchone()
        SupplierID = fetchSupplierID[0]
        return(SupplierID)

    def findSupplierEmail(self,SupplierID):
        self.db.open_conn()
        self.db.cur.execute("SELECT SupplierEmail FROM Suppliers WHERE SupplierID=?", (SupplierID,))
        fetchEmail = self.db.cur.fetchone()
        supplierEmail = fetchEmail[0]
        return(supplierEmail)

    def mailSend(self,amountRequired,nameOfProduct,stockProductID):
        #import smtplib
        #server = smtplib.SMTP('smtp.gmail.com', 587)
        #server.ehlo()
        #server.starttls()
        CategoryID = self.findCategoryID(stockProductID)
        SupplierID = self.findSupplierID(CategoryID)
        supplierEmail = self.findSupplierEmail(SupplierID)
        #myemail = 'sam.sutton1700@gmail.com'
        #mypwd = 'Mynumberis10'
        #recip = supplierEmail
        #server.login(myemail,mypwd)
        #msg = "Can I order "+str(amountRequired)+" "+str(nameOfProduct)+" to arrive as soon as possible. Thanks"
        #server.sendmail(myemail, recip, msg)
        #print("SUCCESS")
        #server.quit()
        self.insertToStockReOrders(stockProductID,amountRequired)

    def checkStockReOrdered(self,nameOfProduct,amountRequired,stockProductID):
        OrderDec = input("Do you want to re-order "+str(amountRequired)+" of  '"+str(nameOfProduct)+"' (Y/N) > ")
        if OrderDec == "Y":
            print ("Please wait, whilst the order is processing")
            self.mailSend(amountRequired,nameOfProduct,stockProductID)
        elif OrderDec == "N":
            print("Stock will not be re-ordered this time")
        else:
            print("Incorrect format entered")
            self.checkStockReOrdered(nameOfProduct,amountRequired,stockProductID)


    def stockLastWeek(self):
        productSoldList = []
        productIDList = []
        self.db.open_conn()
        datenow = (datetime.now())
        #############
        lastWeek = datenow - timedelta(7)
        #########
        self.db.cur.execute("SELECT sum(OrderItems.Qty) FROM Orders, OrderItems, Product WHERE Orders.OrderID = OrderItems.OrderID and OrderItems.ProductID = Product.ProductID and Orders.DateOfOrder >= '" + str(lastWeek) + "' and Orders.DateOfOrder <= '" + str(datenow) + "' GROUP BY Product.ProductID")
        printPro = self.db.cur.fetchall()
        self.db.cur.execute("SELECT Product.ProductID FROM Orders, OrderItems, Product WHERE Orders.OrderID = OrderItems.OrderID and OrderItems.ProductID = Product.ProductID and Orders.DateOfOrder >= '" + str(lastWeek) + "' and Orders.DateOfOrder <= '" + str(datenow) + "' GROUP BY Product.ProductID")
        printProductID = self.db.cur.fetchall()
        self.listAppendLoop(printPro, productSoldList, printProductID, productIDList)
        self.weeklyProductStockCheck(printPro, productSoldList, productIDList)
        self.db.disconnect()

    def listAppendLoop(self,printPro,productSoldList,printProductID,productIDList):
        for loop in range(0,len(printPro)):
            productStockLevel=(printPro[loop])
            productStock=productStockLevel[0]
            productSoldList.append(productStock)
            productIDLoop = printProductID[loop]
            productID = productIDLoop[0]
            productIDList.append(productID)
        return (productSoldList,productIDList)

    def weeklyProductStockCheck(self,printPro,productSoldList,productIDList):
        for loop in range (0,len(printPro)):
            print("---")
            AmountOfProductSold = productSoldList[loop]
            stockProductID = productIDList[loop]
            self.db.open_conn()
            self.db.cur.execute("SELECT Stock FROM Product WHERE ProductID=?",(stockProductID,))
            stockOfProduct0 = self.db.cur.fetchone()
            stockOfProduct = stockOfProduct0[0]
            self.db.cur.execute("SELECT Name FROM Product WHERE ProductID=?", (stockProductID,))
            nameOfProduct0 = self.db.cur.fetchone()
            nameOfProduct = nameOfProduct0[0]
            if AmountOfProductSold > stockOfProduct:
                print(str(nameOfProduct)+ " will be out of stock soon")
                amountRequired = AmountOfProductSold - stockOfProduct
                self.checkStockReOrdered(nameOfProduct,amountRequired,stockProductID)

            else:
                print("")
