# Database Directory

## Purpose
This directory stores the text-based database files used by the Banking System application.

## Contents
When the application runs, it creates and maintains the following files:
- `bank_accounts.txt`: Stores all bank account information in CSV format

## File Format
Each line in the `bank_accounts.txt` file represents a single account with the following format:
```
account_number,name,age,gender,balance,date_of_creation
```

Example:
```
1001,John Doe,30,M,5000.00,2023-04-24
1002,Jane Smith,28,F,7500.50,2023-04-25
```

## Notes
- This directory is required for the application to function properly.
- The database file is automatically created when the application is first run.
- The data files themselves are excluded from version control to protect privacy and prevent repository bloat.
- **Do not manually edit** these files unless you understand the data format, as incorrect edits may corrupt the database. 