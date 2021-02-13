#include <iostream>
#define MAX 100 using namespace std;

class customer
{

  int house, telephone, license;
  int purchase;

public:
  static int total;
  int cn;
  customer() {}

  void set_details(int h, int t, int l)
  {
    house = h;
    telephone = t;
    license = l;
    purchase = 0;
    cn = ++total;
  }

  void add_purchase(int val)
  {
    purchase += val;
  }
  void reset_purchase()
  {
    purchase = 0;
  }

  int get_purchase()
  {
    return purchase;
  }
  void get_details()
  {
    cout << "House: " << house << endl;
    cout << "Telephone: " << telephone << endl;
    cout << "License: " << license << endl;
    cout << "Purchase: " << purchase << endl;
    cout << endl;
  }
};
void swap(customer arr[], int i, int j)
{
  customer temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}

int customer::total = 0;

int main()
{

  int n;
  cout << "Enter the no of customers to deal with: ";
  cin >> n;
  customer record[MAX];
  cout << "Enter the House, Telephone and License for each customer:\n";
  int h, t, l;

  for (int i = 0; i < n; i++)
  {
    cout << "CN = " << (i + 1) << ": ";
    cin >> h >> t >> l;
    record[i].set_details(h, t, l);
  }

  cout << "Choose from the options:\n";
  cout << "(P)urchase | (D)eclare Winners | (Q)uit\n";
  char choice;
  while ((choice = getchar()) != 'Q')
  {
    switch (choice)
    {
    case 'P':
    {
      cout << "Enter the customer no: ";
      int id, val;
      cin >> id;
      int index; // index at which given cn is located
      for (int i = 0; i < n; i++)
        if (id == record[i].cn)
        {
          index = i;
          break;
        }

      cout << "Enter the amount of purchase: ";
      cin >> val;
      record[index].add_purchase(val);
    }

    break;
    case 'D':
    {
      // sort the record arr by amount of purchase
      for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
        {
          if (record[i].get_purchase() < record[j].get_purchase())
            swap(record, i, j);
        }
      cout << "The Winners are:\n";
      for (int i = 0; i < 10 && i < n; i++)
        record[i].get_details();
      for (int i = 0; i < n; i++)
        record[i].reset_purchase();
      cout << "The purchases has been now reset.\n";
    }
    }
  }
}

//Question 2

#include <bits/stdc++.h>
using namespace std;
class Customer
{
private:
  string address;
  long cn;
  long orders;
  long Payment;

public:
  Customer(string ad, long customer_Num)
  {
    address = ad;
    cane = custNum;
    orders = 0;
    Payment = 0;
  }
  string getAddress()
  {
    return address;
  }
  long getCustomer_Num()
  {
    return cn;
  }
  bool is Credit_Worthy()
  {
    if (orders == 0)
      return true;
    return (P100) / orders >= 50;
  }
  void inc_Order()
  {
    orders++;
  }
  void incPayment()
  {
    Payment++;
  }
};
class Commodity
{
private:
  long commodity_Id;
  long Price;
  string commodity_Name;
  long dealer_Id;

public:
  Commodity(long id, long price, string name, long deal)
  {
    Commodity_Id = cmd_id;
    Price = price;
    Commodity_Name = name;
    Dealer_Id = deal;
  }
  long getCommodityId()
  {
    return commodity_Id;
  }
  long getUnitPrice()
  {
    return Price;
  }
  string getCommodityName()
  {
    return commodity_Name;
  }
  long getDealerId()
  {
    return dealer_Id;
  }
};
class Item
{
private:
  long commodity_Id;
  long quantity;

public:
  Item(long id, long qnt)
  {
    Commodity_Id = id;
    quantity = qnt;
  }
  long getCommodityId()
  {
    return commodity_Id;
  }
  long getQuantity()
  {
    return qnt;
  }
  void setQuantity(long newQty)
  {
    quantity = newQty;
  }
};
class Order
{
private:
  vector<Item> items;
  long cn;
  long orderId;
  time_t placedAt;

public:
  Order(long custNum)
  {
    cn = cust_Num;
  }
  long getCustNum()
  {
    return cn;
  }
  long getOrderId()
  {
    return orderId;
  }
  void setOrderId(long oId)
  {
    orderId = oId;
  }
  time_t getPlacementTime()
  {
    return placedAt;
  }
  void setPlacementTime()
  {
    placedAt = time(0);
  }
  vector<Item> getItems()
  {
    return items;
  }
  bool isItemPresent(long itemId)
  {
    for (int i = 0; i < items.size(); i++)
    {
      if (items[i].getCommodityId() == itemId)
      {
        return true;
      }
    }
    return false;
  }
  bool isEmpty()
  {
    return items.size() == 0;
  }
  void addItem(Item item)
  {
    items.push_back(item);
  }
  void updateItem(long itemId, long qty)
  {
    for (int i = 0; i < items.size(); i++)
    {
      if (items[i].getCommodityId() == itemId)
      {
        items[i].setQuantity(qty);
        return;
      }
    }
  }
};
class Dealer
{
private:
  string dealerName;

public:
  Dealer(string name)
  {
    dealerName = name;
  }
  string getDealerName()
  {
    return dealerName;
  }
};
vector<Dealer> dealers;
void prepareDealerData()
{
  dealers.push_back(Dealer("Pro Matchstick Dealers"));
  dealers.push_back(Dealer("Kiran Edibles"));
  dealers.push_back(Dealer("Saleem Healthcare"));
}
vector<Commodity> commodities;
void prepareOverallCommoditiesList()
{
  prepareDealerData();
  commodities.push_back(Commodity(1, 20, "Matchsticks", 0));
  commodities.push_back(Commodity(2, 60, "Sunflower Oil", 1));
  commodities.push_back(Commodity(3, 100, "Detergent", 2));
  commodities.push_back(Commodity(4, 70, "Bathing Soap", 2));
  commodities.push_back(Commodity(5, 35, "Brown Bread", 1));
}
Commodity searchCommodity(long commodityId)
{
  Commodity commodity(-1, -1, "ABCD", 0);
  for (int i = 0; i < commodities.size(); i++)
  {
    if (commodities[i].getCommodityId() == commodityId)
      return commodities[i];
  }
  return commodity;
}
class TradingHouse
{
private:
  const double TIME_THRESHOLD = 120;
  vector<Customer> customers;
  vector<Order> orders;
  vector<bool> paymentCompleted;
  vector<Item> inventory;
  vector<Order> pendingOrders;
  vector<Item> records;

public:
  TradingHouse();
  void prepareInventory();
  void registerCustomer();
  void prepareOrderList();
  void processOrder(Order order, int customerIdx);
  void handleIndentRequest();
  void managerialQuery();
  void issuePayment();
  bool isCommodityDealt(long commodityId)
  {
    return getInventoryIndex(commodityId) != -1;
  }
  long getInventoryIndex(long commodityId)
  {
    for (int i = 0; i < inventory.size(); i++)
    {
      if (inventory[i].getCommodityId() == commodityId)
        return i;
    }
    return -1;
  }
  long getCustomerIndex(long custNum)
  {
    for (int i = 0; i < customers.size(); i++)
    {
      if (customers[i].getCustNum() == custNum)
      {
        return i;
      }
    }
    return -1;
  }
  long getRecordsIndex(long commodityId)
  {
    for (int i = 0; i < records.size(); i++)
    {
      if (records[i].getCommodityId() == commodityId)
      {
        return i;
      }
    }
    return -1;
  }
  long getOrderIndex(long orderId)
  {
    for (int i = 0; i < orders.size(); i++)
    {
      if (orders[i].getOrderId() == orderId)
      {
        return i;
      }
    }
    return -1;
  }
  void clearRecords()
  {
    records.clear();
    records = vector<Item>(inventory);
    for (int i = 0; i < records.size(); i++)
      records[i].setQuantity(0);
  }
};
TradingHouse::TradingHouse()
{
  prepareInventory();
}
void TradingHouse::prepareInventory()
{
  inventory.push_back(Item(2, 5));
  inventory.push_back(Item(4, 5));
  inventory.push_back(Item(5, 5));
}
void TradingHouse::registerCustomer()
{
  int newCustId = customers.size() + 1;
  string res;
  fflush(stdin);
  cout << "\nEnter customer address:";
  getline(cin, res);

  Customer customer(res, newCustId);
  customers.push_back(customer);

  cout << "Customer registered successfully.\n";
  cout << "Customer Identification Number : " << newCustId << "\n\n";
}
void TradingHouse::prepareOrderList()
{
  long custNum, itemId, qty, idx;
  cout << "\nEnter customer number:";
  cin >> custNum;

  idx = getCustomerIndex(custNum);
  if (idx == -1)
  {
    cout << " Please try again.\n\n";
    return;
  }
  if (customers[idx].isCreditWorthy() == false)
  {
    cout << " our organization rules do not allow accepting orders from you.\n\n";
    return;
  }
  Order order(custNum);

  while (true)
  {
    cout << "\n0.\tCheck-out\n";
    for (int i = 0; i < commodities.size(); i++)
    {
      cout << commodities[i].getCommodityId() << "\t" << commodities[i].getCommodityName() << "\n";
    }
    cout << "\nEnter your choice:";
    cin >> itemId;
    if (itemId == 0)
    {
      if (order.isEmpty())
      {
        cout << "Enter at least one item.\n";
        continue;
      }
      else
      {
        break;
      }
    }

    if (order.isItemPresent(itemId))
    {
      cout << "Enter updated quantity:";
      cin >> qty;
      order.updateItem(itemId, qty);
      cout << "Item updated.\n";
    }
    else
    {
      cout << "Enter quantity:";
      cin >> qty;
      order.addItem(Item(itemId, qty));
      cout << "Item added.\n";
    }
  }

  processOrder(order, idx);
}
void TradingHouse::processOrder(Order order, int customerIdx)
{
  vector<long> regret;
  vector<Item> orderItems = order.getItems();

  Order finalOrder(order.getCustNum());
  Order pendingOrder(order.getCustNum());

  for (int i = 0; i < orderItems.size(); i++)
  {
    if (!isCommodityDealt(orderItems[i].getCommodityId()))
    {
      regret.push_back(orderItems[i].getCommodityId());
    }
  }
  if (!regret.empty())
  {
    cout << "\nUnfortunately, we do not deal in the following items.\n";
    for (int i = 0; i < regret.size(); i++)
    {
      cout << searchCommodity(regret[i]).getCommodityName() << "\n";
    }
  }
  cout << "\n";
  if (regret.size() == orderItems.size())
  {
    return;
  }
  for (int i = 0; i < orderItems.size(); i++)
  {
    long commodityId = orderItems[i].getCommodityId();
    if (!isCommodityDealt(commodityId))
      continue;
    long stockIdx = getInventoryIndex(commodityId);
    long stockQty, orderQty;
    orderQty = orderItems[i].getQuantity();
    stockQty = inventory[stockIdx].getQuantity();
    if (stockQty < orderQty)
    {
      pendingOrder.addItem(orderItems[i]);
    }
    else
    {
      finalOrder.addItem(orderItems[i]);
      inventory[stockIdx].setQuantity(stockQty - orderQty);
    }
  }

  if (!pendingOrder.isEmpty())
  {
    pendingOrders.push_back(pendingOrder);
  }
  if (finalOrder.isEmpty())
  {
    cout << "Sorry, none of your requested items were in stock.\nOrder will be placed as and when items
            become available.\n\n ";
            return;
  }
  finalOrder.setPlacementTime();
  finalOrder.setOrderId(orders.size() + 1);
  orders.push_back(finalOrder);
  paymentCompleted.push_back(false);
  customers[customerIdx].incrementOrder();
  orderItems = finalOrder.getItems();
  cout << "\nInvoice:\n";
  cout << "Order ID:" << finalOrder.getOrderId() << "\n";
  cout << "Customer Identification Number:" << customers[customerIdx].getCustNum() << "\n";
  cout << "Billing Address:" << customers[customerIdx].getAddress() << "\n";
  cout << "Items:\n";
  long totalPrice = 0;
  for (int i = 0; i < orderItems.size(); i++)
  {
    long commodityId = orderItems[i].getCommodityId();
    string itemName = searchCommodity(commodityId).getCommodityName();
    cout << itemName << "\t" << orderItems[i].getQuantity() << "\n";
    totalPrice += (orderItems[i].getQuantity() * searchCommodity(commodityId).getUnitPrice());
  }
  cout << "\nTotal billable amount:" << totalPrice << "\n\n";
}
void TradingHouse::handleIndentRequest()
{
  vector<vector<Item>> indent(dealers.size());

  for (int orderIdx = 0; orderIdx < pendingOrders.size(); orderIdx++)
  {
    vector<Item> orderItems = pendingOrders[orderIdx].getItems();
    for (int itemIdx = 0; itemIdx < orderItems.size(); itemIdx++)
    {
      Commodity commodity = searchCommodity(orderItems[itemIdx].getCommodityId());
      indent[commodity.getDealerId()].push_back(orderItems[itemIdx]);
    }
  }
  cout << "\nIndents:\n";
  for (int dealer = 0; dealer < dealers.size(); dealer++)
  {
    if (indent[dealer].empty())
      continue;
    cout << "Dealer Name:" << dealers[dealer].getDealerName() << "\n";
    cout << "Items:\n";
    for (int item = 0; item < indent[dealer].size(); item++)
    {
      cout << searchCommodity(indent[dealer][item].getCommodityId()).getCommodityName()
           << "\t" << indent[dealer][item].getQuantity() << "\n";
    }
    cout << "\n";
  }
  for (int orderIdx = 0; orderIdx < pendingOrders.size(); orderIdx++)
  {
    vector<Item> orderItems = pendingOrders[orderIdx].getItems();
    for (int itemIdx = 0; itemIdx < orderItems.size(); itemIdx++)
    {
      long inventoryIdx = getInventoryIndex(orderItems[itemIdx].getCommodityId());
      long newQty = inventory[inventoryIdx].getQuantity() + orderItems[itemIdx].getQuantity();
      inventory[inventoryIdx].setQuantity(newQty);
    }

    long customerIdx = getCustomerIndex(pendingOrders[orderIdx].getCustNum());
    processOrder(pendingOrders[orderIdx], customerIdx);
  }
  pendingOrders.clear();
}
void TradingHouse::issuePayment()
{
  long orderId;
  cout << "\nEnter order number:";
  cin >> orderId;
  long orderIdx = getOrderIndex(orderId);
  if (orderIdx == -1)
  {
    cout << "Invalid order ID.\n\n";
    return;
  }
  long custNum = orders[orderIdx].getCustNum();
  long custIdx = getCustomerIndex(custNum);
  time_t curr = time(0);

  if (paymentCompleted[orderIdx])
  {
    cout << "\nPayment has already been completed.\n";
    return;
  }
  if (difftime(curr, orders[orderIdx].getPlacementTime()) < TIME_THRESHOLD)
  {
    customers[custIdx].incrementPayment();
  }
  paymentCompleted[orderIdx] = true;
  cout << "Payment Completed\n\n";
}
void TradingHouse::managerialQuery()
{

  clearRecords();
  for (int orderIdx = 0; orderIdx < orders.size(); orderIdx++)
  {
    vector<Item> orderItems = orders[orderIdx].getItems();
    for (int itemIdx = 0; itemIdx < orderItems.size(); itemIdx++)
    {
      long recordIdx = getRecordsIndex(orderItems[itemIdx].getCommodityId());
      if (recordIdx == -1)
      {
        continue;
      }
      else
      {
        long newQty = records[recordIdx].getQuantity() + orderItems[itemIdx].getQuantity();
        records[recordIdx].setQuantity(newQty);
      }
    }
  }
  cout << "Sales of all items dealt:\n";
  for (int recordIdx = 0; recordIdx < records.size(); recordIdx++)
  {
    cout << searchCommodity(records[recordIdx].getCommodityId()).getCommodityName() << "\t";
    cout << records[recordIdx].getQuantity() << "\n";
  }
  cout << "\n";
}
int main()
{
  prepareOverallCommoditiesList();
  TradingHouse house;
  int choice;
  cout << "Welcome to Trading House Automation System!\n";
  while (true)
  {
    cout << "Options:\n";
    cout << "1. Register Customer\n";
    cout << "2. Place order\n";
    cout << "3. Issue payment\n";
    cout << "4. Handle indents\n";
    cout << "5. Managerial query\n";
    cout << "6. Exit\n";
    cout << "Enter your choice:";
    fflush(stdin);
    cin >> choice;
    switch (choice)
    {
    case 1:
      house.registerCustomer();
      break;
    case 2:
      house.prepareOrderList();
      break;
    case 3:
      house.issuePayment();
      break;
    case 4:
      house.handleIndentRequest();
      break;
    case 5:
      house.managerialQuery();
      break;
    case 6:
      exit(0);
      break;
    default:
      cout << "Invalid choice. Please try again.\n\n";
      break;
    }
  }
}