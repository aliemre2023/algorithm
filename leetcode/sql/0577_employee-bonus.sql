SELECT 
    Employee.name AS name,
    Bonus.bonus AS bonus
FROM Employee
LEFT JOIN Bonus ON Bonus.empId = Employee.empId
WHERE bonus < 1000 OR bonus IS NULL;