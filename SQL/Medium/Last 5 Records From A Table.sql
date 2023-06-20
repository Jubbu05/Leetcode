-- (SELECT * FROM Employee ORDER BY ID DESC LIMIT 5)
-- ORDER BY ID ASC;

SELECT TOP 5 * FROM Employee
ORDER BY ID DESC;

SELECT * FROM Employee
WHERE 
ID > (SELECT COUNT(*) FROM Employee) - 5;