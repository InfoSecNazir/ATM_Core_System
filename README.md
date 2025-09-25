 
# 🏧 Simple ATM System (C++)

This project is a **simple ATM (Automated Teller Machine) simulation** that runs on the console.  
It is developed using **C++** and focuses on the core functionalities expected from a real ATM.  
Customer data and account balances are stored in a text file (`Cilent.txt`) to ensure data persistence between sessions.

---

## 🚀 Features

- **Secure Login System**  
  Requires the user to enter the **Account Number** and **PIN Code** to access their account.  

- **Quick Withdraw**  
  Provides a list of predefined amounts (e.g., `20`, `50`, `100`) for fast withdrawal.  

- **Normal Withdraw**  
  Allows the user to enter a custom amount (must be a multiple of 5).  

- **Deposit**  
  Enables the user to deposit money into their account.  

- **Check Balance**  
  Displays the current account balance.  

- **Logout**  
  Safely logs the user out and returns to the login screen.  

- **Data Persistence**  
  All changes are saved automatically into the `Cilent.txt` file.  

---

## 🛠️ Installation & Run

You will need a **C++ compiler** such as `g++` or **MinGW**.  

### 1. Clone the repository
```bash
git clone https://github.com/your-username/your-repository-name.git
````

### 2. Navigate into the project folder

```bash
cd your-repository-name
```

### 3. Compile the code

```bash
g++ main.cpp -o atm
```

> Replace `main.cpp` with the actual file name if different.

### 4. Create the data file

Before running the program for the first time, create a file named **`Cilent.txt`** in the same folder.
Add some initial customer data using this format:

```
Account_Number||PinCode||Name||Phone_Number||Balance
```

**Example:**

```
A1001||1234||Ali Hassan||0501234567||5000
A1002||5555||Fatima Ahmed||0559876543||8250.5
```

### 5. Run the program

* On **Windows**:

```bash
atm.exe
```

* On **Linux / macOS**:

```bash
./atm
```

---

## 📂 Data File Structure

* File name: **Cilent.txt**
* Each line represents a single client.
* Fields are separated using `||`.

**Format:**

```
Account_Number||PinCode||Name||Phone_Number||Balance
```

This makes it easy to add or edit client data manually if necessary.

```

 ```
