WITH cte AS{
    SELECT *, CASE WHEN type='Deposite' THEN amount ELSE -amount END AS amount 
    FROM Transactions 
}

SELECT 
  account_id, 
  day,
  SUM(amount) OVER (PARTITION BY account_id ORDER BY day ROWS BETWEEN UNBOUNDED PRECEDING AND CURRENT+ AS balance
FROM cte
ORDER BY account_id, day
