from DatabaseSetup import database
class reOrderCheck():
    def __init__(self):
        self.db = database()

    def sameQuantity(self):
        sameQuantity = input("You have entered a quantity which is same as the amount you orginally ordered, is this correct? (y/n)")
        if sameQuantity == "y":
            print("")
        else:
            # go back
            pass

    def greaterQuantity(self):
        moreQuantity = input("You have entered a quantity which is greater than the amount you orginally ordered, is this correct? (y/n)")
        if moreQuantity == "y":
            print("")
        else:
            # go back
            pass



    def showAllReOrders(self):
        self.db.open_conn()
        self.db.cur.execute('SELECT * FROM ReOrders WHERE Completed = "N"')
        reOrder = self.db.cur.fetchall()
        print(reOrder)
        return(reOrder)

    def updateQuantity(self,quantityArrived,quantityRequested,reorderID):
        print(quantityArrived)
        quantityUpdated = quantityRequested - quantityArrived
        self.db.cur.execute("UPDATE ReOrders SET Quantity=? WHERE ReOrderID=?", (quantityUpdated,reorderID,))
        self.selectReOrder(reorderID)
        self.db.db_conn.commit()

    def orderPart(self,reorderID):
        self.db.cur.execute("SELECT Quantity FROM ReOrders WHERE ReOrderID=?", (reorderID,))
        quantityRequested0 = self.db.cur.fetchone()
        quantityRequested = quantityRequested0[0]
        return(quantityRequested)

    def selectReOrder(self,reorderID):
        self.db.cur.execute("SELECT * FROM ReOrders WHERE ReOrderID=?", (reorderID,))
        reOrderProduct = self.db.cur.fetchone()
        print(reOrderProduct)

    def orderArrived(self,reorderID):
        self.selectReOrder(reorderID)
        orderDecision = input("Has the order arrived fully> (y/n)")
        if orderDecision == "y":
            self.orderUpdate(reorderID)
        elif orderDecision == "n":
            arrived = input("Has any of the selected product arrived? (y/n) ")
            if arrived == "y":
                quantityRequested = self.orderPart(reorderID)
                quantityArrived = int(input("How many have arrived? "))
                if quantityArrived > quantityRequested:
                    self.greaterQuantity()
                elif quantityArrived == quantityRequested:
                     self.sameQuantity()
                else:
                     self.updateQuantity(quantityArrived, quantityRequested, reorderID)
            elif arrived == "n":
                print("No changes made to the database")

            else:
                quit()
                # self.orderArrived(reorderID)

    def orderUpdate(self,reorderID):
        completedField = "Y"
        self.db.cur.execute("UPDATE ReOrders SET Completed=? WHERE ReOrderID=?", (completedField, reorderID,))
        self.db.db_conn.commit()
        print("")

    def orderCheck(self):
        reOrder = self.showAllReOrders()
        listLength = (len(reOrder))
        print(listLength)
        if listLength < 1 :
            print("No Orders Expected")
        else:
            print(len(reOrder))
            listLength0 = ((len(reOrder)-1))
            print(listLength0)
            for loop in (0, listLength0):
                orderCheck = (reOrder[loop])
                print(orderCheck)
                reorderID = (orderCheck[0])

                #print(reorderID)
                #self.orderArrived(reorderID)
                #self.selectReOrder(reorderID)

                orderDecision = input("Has the order arrived fully> (y/n)")
                if orderDecision == "y":
                    self.orderUpdate(reorderID)
                elif orderDecision == "n":
                    arrived = input("Has any of the selected product arrived? (y/n) ")
                    #if arrived == "y":
                    #    quantityRequested = self.orderPart(reorderID)
                    #    quantityArrived = int(input("How many have arrived? "))
                    #    if quantityArrived > quantityRequested:
                    #        self.greaterQuantity()
                    #    elif quantityArrived == quantityRequested:
                    #        self.sameQuantity()
                    #    else:
                    #        self.updateQuantity(quantityArrived, quantityRequested, reorderID)
                    #elif arrived == "n":
                    #    print("No changes made to the database")
                    #else:
                    #    pass

                else:
                    pass

ReOrd = reOrderCheck()
ReOrd.orderCheck()