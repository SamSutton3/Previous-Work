from DatabaseSetup import database
class reOrder():
    def __init__(self):
        self.db = database()
    def show_all_reOrders(self):
        self.db.open_conn()
        print("")
        self.db.cur.execute('SELECT * FROM ReOrders WHERE Completed = "N"')
        reOrder = self.db.cur.fetchall()
        print("Orders waiting "+str(reOrder))
        self.db.disconnect()
        print("")
        return(reOrder)

    def check(self):
        reOrder = self.show_all_reOrders()

        if len(reOrder) > 0 :
            for loop in range(0,len(reOrder)):

                reOrderProduct = (reOrder[loop])
                reOrderID = reOrderProduct[0]

                reOrderDecision = input("Has "+str(reOrderProduct)+" arrived fully? (y/n) ")
                if reOrderDecision == "y":
                    completedField = "Y"
                    self.db.cur.execute("UPDATE ReOrders SET Completed=? WHERE ReOrderID=?",(completedField, reOrderID,))
                    self.db.db_conn.commit()

                elif reOrderDecision == "n":

                    reOrderDecision0 = input("Has any of the order arrived? (y/n) ")
                    if reOrderDecision0 == "y":
                        self.db.cur.execute("SELECT Quantity FROM ReOrders WHERE ReOrderID=?", (reOrderID,))
                        quantityRequested0 = self.db.cur.fetchone()
                        quantityRequested = quantityRequested0[0]

                        quantityArrived = int(input("How much of the product has arrived > "))
                        if quantityArrived > -1:

                            if quantityArrived > quantityRequested:
                                print("More arrived than what you ordered")
                                completedField = "Y"
                                self.db.cur.execute("UPDATE ReOrders SET Completed=? WHERE ReOrderID=?",(completedField, reOrderID,))
                                self.db.db_conn.commit()
                                self.db.cur.execute("SELECT ProductID FROM ReOrders WHERE ReOrderID=?",(reOrderID,))
                                productID0 = self.db.cur.fetchone()
                                productID = productID0[0]
                                self.db.cur.execute("SELECT Stock FROM Product WHERE ProductID=?",(productID,))
                                stock0 = self.db.cur.fetchone()
                                stock = stock0[0]
                                stockNew = stock + quantityArrived
                                self.db.cur.execute("UPDATE Product SET Stock=? WHERE ProductID=?",(stockNew, productID,))
                                self.db.db_conn.commit()

                            elif quantityArrived == quantityRequested:
                                completedField = "Y"
                                self.db.cur.execute("UPDATE ReOrders SET Completed=? WHERE ReOrderID=?",(completedField, reOrderID,))
                                self.db.db_conn.commit()
                                self.db.cur.execute("SELECT ProductID FROM ReOrders WHERE ReOrderID=?",(reOrderID,))
                                productID0 = self.db.cur.fetchone()
                                productID = productID0[0]
                                self.db.cur.execute("SELECT Stock FROM Product WHERE ProductID=?",(productID,))
                                stock0 = self.db.cur.fetchone()
                                stock = stock0[0]
                                stockNew = stock + quantityArrived
                                self.db.cur.execute("UPDATE Product SET Stock=? WHERE ProductID=?",(stockNew, productID,))
                                self.db.db_conn.commit()

                            elif quantityArrived < quantityRequested:
                                quantityTotal = quantityRequested - quantityArrived
                                self.db.cur.execute("UPDATE ReOrders SET Quantity=? WHERE ReOrderID=?",(quantityTotal, reOrderID,))
                                self.db.db_conn.commit()
                                self.db.cur.execute("SELECT ProductID FROM ReOrders WHERE ReOrderID=?",(reOrderID,))
                                productID0 = self.db.cur.fetchone()
                                productID = productID0[0]
                                self.db.cur.execute("SELECT Stock FROM Product WHERE ProductID=?",(productID,))
                                stock0 = self.db.cur.fetchone()
                                stock = stock0[0]
                                stockNew = stock + quantityArrived
                                self.db.cur.execute("UPDATE Product SET Stock=? WHERE ProductID=?",(stockNew, productID,))
                                self.db.db_conn.commit()

                            else:
                                print("Incorrect format - Will Skip")
                                pass

                        else:
                            print("Incorrect format - Negative number")
                            pass

                    elif reOrderDecision0 == "n":
                        print("The order has not arrived yet")
                        pass

                    else:
                        print("Incorrect format")
                        pass

                else:
                    print("Incorrect Format - Will Skip")
                    pass

        else:
            print("No orders expected")
            pass

        self.show_all_reOrders()
ReOrd = reOrder()
ReOrd.check()
