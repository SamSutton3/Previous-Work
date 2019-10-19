from DatabaseSetup import database
from OrderDatabase1 import order
from StockReOrdering import ReOrdering

mydb = database()
myord = order()
mydb.open_conn()

mydb.create_table("Products")
mydb.create_table("Category")
mydb.create_table("Products_Category1")
mydb.create_table("Orders")
mydb.create_table("OrderItems1")
mydb.create_table("Users2")
mydb.create_table("Permissions")
mydb.create_table("User_Permissions")
mydb.create_table("Permissions")
mydb.create_table("User_Permissions")
mydb.create_table("Suppliers")
mydb.create_table("Supplier_Category")
mydb.create_table("Stock_ReOrders1")

#mydb.insert_suppliers()
#mydb.insert_suppliers_category()
#mydb.show_all_suppliers_categories()
#mydb.edit_user()
#mydb.insert_permission_group()
#mydb.show_all_permission_groups()
mydb.assign_user()
#mydb.show_all_productsCat()
#mydb.edit_product()
#mydb.insert_product()
#myord.orderRunner()
#ReOrd = ReOrdering()
#ReOrd.stockLastWeek()
#mydb.add_user()

###
##suppliers for items#################
##yes/no to reorder#####################
##save orders into database############
##has the order been completed correctly?
## NO? -
## YES? - DELETE
###


