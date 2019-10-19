from DatabaseSetup import database
from MenuSystem import menu
class userLogin():
    def __init__(self):
        self.db = database()
    def menuServer(self):
        print("Server")
        print(" === SERVER MENU === ")
        print("1 : Take an Order")
        print("2 : Logout")

        f = False
        while f == False:
            serverDecision = (input(">> "))
            if serverDecision == "1":
                print("Order")
                f = True
            elif serverDecision == "2":
                print("Logout")
                f = True
            else:
                print("Invalid")
                f = False



    def menuTrusted(self):
        print("Trusted")
    def menuOwner(self):
        print("Owner")

    def menuSelector(self,PermissionID):
        if PermissionID  == 1:
            self.menuOwner()
        elif PermissionID == 2:
            self.menuTrusted()
        elif PermissionID == 3:
            self.menuOwner()
        else:
            print("ERROR")

    def menuRunner(self,usernameEnter):
        self.db.open_conn()
        self.db.cur.execute("SELECT UserID FROM Users WHERE Username=?",(usernameEnter))
        fetchID = self.db.cur.fetchone()
        UserID = fetchID[0]
        print(UserID)
        self.db.cur.execute("SELECT PermissionsID FROM User_Permissions WHERE UserID=?",(UserID,))
        fetchPermissionID = self.db.cur.fetchone()
        PermissionID = fetchPermissionID[0]
        self.menuSelector(PermissionID)

    def login(self):
        self.db.open_conn()
        self.db.cur.execute("SELECT * from Users")
        dbuser = self.db.cur.fetchall()
        print(dbuser)
        usernameEnter = input ("Username> ")
        passwordEnter = input("Password> ")
        for loop in range(0,len(dbuser)):
            dbuserLoop=dbuser[loop]
            print(dbuserLoop)
            dbuserLoop0 = dbuserLoop[1]
            if usernameEnter == dbuserLoop0:
                dbPassword = dbuser[loop]
                dbPasswordLoop = dbPassword[2]
                if passwordEnter == dbPasswordLoop:
                    self.menuRunner(usernameEnter)
                else:
                    pass
            else:
                pass
        quit()




uL = userLogin()
uL.menuServer()

