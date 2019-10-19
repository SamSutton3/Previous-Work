from DatabaseSetup import database
from datetime import datetime, date
import sqlite3
class order():
    def __init__(self):
        self.db = database()
        pass

    def inputPurchase(self):
        purchase = input("ProductID> ")
        if purchase.isdigit():
            return(purchase)
        else:
            print("You did not type in a correct Product ID")
            quit()

    def selectPurchase(self, purchase):
        self.db.cur.execute("SELECT Name from Product where ProductID=?", (purchase,))
        productSelected = self.db.cur.fetchone()
        print("You have selected ", (productSelected))

    def selectPriceForProduct(self,purchase):
        self.db.cur.execute('Select Price from Product where ProductID =? ', (purchase,))
        tupledPrice = self.db.cur.fetchone()
        productPrice = tupledPrice[0]
        print("Product Price:", productPrice)
        return(productPrice)

    def selectQuantity(self):
        quantityInput = int(input("Quantity> "))
        return(quantityInput)

    def setStock(self, purchase):
        self.db.cur.execute('UPDATE Product SET Stock = (Stock-1) WHERE ProductID =?', (purchase,))
        self.db.db_conn.commit()

    def productStockChecker(self,quantityInput,purchase):
        for loop in range(0, quantityInput):
            self.db.cur.execute('Select Stock from Product where ProductID =? ', (purchase,))
            LoopStock1 = self.db.cur.fetchone()
            LoopStock = LoopStock1[0]
            if LoopStock > quantityInput:
                self.setStock(purchase)
            elif LoopStock == quantityInput:
                print("Item selected is now out of stock")
                self.setStock(purchase)
            else:
                print("Insufficient stock")
                self.orderRestart()

    def priceQuantityProducts(self,quantityInput,productPrice):
        quantityProductPrice = productPrice * quantityInput
        print("Product Price with quantity:", quantityProductPrice)

    def cardYorN(self, OrderPrice):
        cardYoN = input("(If they are paying by card - Press any key before ENTER)> ")
        if cardYoN != "":
            OrderPrice = OrderPrice + 0.50
        else:
            pass
        return (OrderPrice)

    def insertIntoOrder(self, OrderPrice0):
        inputDate = datetime.now()
        print(inputDate)
        self.db.cur.execute("INSERT INTO Orders (DateOfOrder,TotalPrice) VALUES (?,?)", (inputDate, OrderPrice0))
        self.db.db_conn.commit()

    def insertIntoOrderItems(self, productOrderList, productPriceList, quantityAmountList):
        self.db.cur.execute("SELECT last_insert_rowid()")
        NextID = self.db.cur.fetchone()
        Next_ID = (NextID[0])
        for loop in range(0, len(productOrderList)):
            updateOrderItems = productOrderList[loop]
            productQuantity = quantityAmountList[loop]
            priceSoldAt0 = productPriceList[loop]
            priceSoldAt = priceSoldAt0 / productQuantit
            self.db.cur.execute("INSERT INTO OrderItems (OrderID,ProductID,Price_Sold_At,Qty) VALUES (?,?,?,?)",(Next_ID, updateOrderItems, priceSoldAt, productQuantity))
            self.db.db_conn.commit()

    def orderRestart(self):
        decision = input("Do you want to restart the order> (Y/N) ")
        if decision == "Y":
            self.orderRunner()
        else:
            quit()

    def orderRunner(self):
        print (" ===== ORDER ===== ")
        OrderPrice = 0
        continueOrder = True
        productOrderList = []
        productPriceList = []
        productSoldAt = []
        quantityAmountList = []
        while continueOrder == True:
            self.db.open_conn()
            self.db.show_all_productsCat()
            print("")
            self.db.open_conn()
            purchase = self.inputPurchase()
            print("")
            self.selectPurchase(purchase)
            print("")
            productPrice = self.selectPriceForProduct(purchase)
            print("")
            quantityInput = self.selectQuantity()
            self.productStockChecker(quantityInput,purchase)
            productPriceTotal = 0
            for loop in range (0,quantityInput):
                productPriceTotal = productPriceTotal + productPrice
            productOrderList.append(purchase)
            productPriceList.append(productPriceTotal)
            quantityAmountList.append(quantityInput)
            OrderPrice = (OrderPrice + productPriceTotal)
            print("")
            self.priceQuantityProducts(quantityInput,productPrice)
            print("")
            continueOrderQ = input("Click enter to continue> ")
            if continueOrderQ != "":
                continueOrder = False
            else:
                continueOrder = True
        print("")
        self.cardYorN(OrderPrice)
        OrderPrice0 = round(OrderPrice,2)
        print("")
        print("===== OVERVIEW ====")
        print("Total Price:", OrderPrice0)
        self.insertIntoOrder(OrderPrice0)
        self.insertIntoOrderItems(productOrderList,productPriceList,quantityAmountList)
