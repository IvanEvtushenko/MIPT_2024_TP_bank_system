#include "Client.h"

int main() {
  std::string req;
  std::cin >> req;
  std::string name, surname, address;
  size_t passport;

  size_t choice_acc;
  double count;
  double limit = 0;
  double fine = 0;
  size_t acceptableDifference = 0;
  size_t client_id = 0;

  size_t choice_tr = 0;
  bool abort = false;
  size_t operationId = 0;

  Bank bank(fine, limit, acceptableDifference);

  while(true) {
    if (req == "Add_cl") {
      std::cin >> name >> surname >> address >> passport;
      bank.AddClient(name, surname, address, passport);
      std::cout << "Client was added\n";
    } else if (req == "Add_acc") {
      std::cin >> client_id >> choice_acc >> count;
      bank.AddAccount(client_id, choice_acc, count);
      std::cout << "Acc. was added\n";
    } else if (req == "Add_tr") {
      std::cin >> choice_tr >> client_id >> choice_acc >> count >> abort >> operationId;
      bank.AddTransaction(choice_tr, client_id, choice_acc, count, abort, operationId);
      std::cout << "Trans. was added\n";
    }
    std::cin >> req;
  }
}