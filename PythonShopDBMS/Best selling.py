from DatabaseSetup import database
from datetime import datetime, timedelta

class Analysis:
    def __init__(self):
        self.db = database()

    def printOutBestSelling(self,topThreeList):
        print("")
        print("Best Selling Item:" + str(topThreeList[0]))
        print("2nd Best Selling Item:" + str(topThreeList[1]))
        print("3rd Best Selling Item:" + str(topThreeList[2]))

    def listChanges(self,bestselling,loopRot,topThreeList):
        appendToList = (bestselling[loopRot])
        topThreeList.append(appendToList)
        bestselling.pop(loopRot)

    def findTopThree(self,bestselling):
        topThree = False
        topThreeList = []
        if len(bestselling) > 2:
            while topThree == False:
                maximum = 0
                for loop in range(0,len(bestselling)):
                    bs=bestselling[loop][3]
                    if bs > maximum:
                        maximum = bs
                        loopRotation = ([loop])
                        loopRot = loopRotation[0]
                    else:
                        pass
                self.listChanges(bestselling,loopRot,topThreeList)
                if len(topThreeList) > 2:
                    topThree = True
                else:
                    pass
            self.printOutBestSelling(topThreeList)
        else:
            print("Not enough Orders to process")

    def bsAllTime(self):
        self.db.open_conn()
        self.db.cur.execute("SELECT Product.ProductId, Product.Name, OrderItems.ProductID, sum(OrderItems.Qty) as Sold, sum(OrderItems.Price_Sold_At * OrderItems.Qty) as TotalSales FROM Orders, OrderItems, Product WHERE Orders.OrderID = OrderItems.OrderID and OrderItems.ProductID = Product.ProductID GROUP BY OrderItems.ProductID")
        bestselling = self.db.cur.fetchall()
        print("All Items Bought: "+str(bestselling))
        self.findTopThree(bestselling)

    def bsMonthly(self):
        self.db.open_conn()
        datenow = (datetime.now())
        lastMonth = datenow - timedelta(30)
        self.db.cur.execute("SELECT Product.ProductId, Product.Name, OrderItems.ProductID, sum(OrderItems.Qty) as Sold, sum(OrderItems.Price_Sold_At * OrderItems.Qty) as TotalSales FROM Orders, OrderItems, Product WHERE Orders.OrderID = OrderItems.OrderID and OrderItems.ProductID = Product.ProductID and Orders.DateOfOrder >= '" + str(lastMonth) + "' and Orders.DateOfOrder <= '" + str(datenow) + "'GROUP BY OrderItems.ProductID")
        bestselling = self.db.cur.fetchall()
        print("All Items Bought: "+str(bestselling))
        self.findTopThree(bestselling)

    def bsWeekly(self):
        self.db.open_conn()
        datenow = (datetime.now())
        lastWeek = datenow - timedelta(7)
        self.db.cur.execute("SELECT Product.ProductId, Product.Name, OrderItems.ProductID, sum(OrderItems.Qty) as Sold, sum(OrderItems.Price_Sold_At * OrderItems.Qty) as TotalSales FROM Orders, OrderItems, Product WHERE Orders.OrderID = OrderItems.OrderID and OrderItems.ProductID = Product.ProductID and Orders.DateOfOrder >= '" + str(lastWeek) + "' and Orders.DateOfOrder <= '" + str(datenow) + "'GROUP BY OrderItems.ProductID")
        bestselling = self.db.cur.fetchall()
        print("All Items Bought: "+str(bestselling))
        self.findTopThree(bestselling)

an = Analysis()
an.bsAllTime()
an.bsMonthly()
an.bsWeekly()