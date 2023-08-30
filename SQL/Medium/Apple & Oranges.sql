WITH cte AS(
    SELECT *
    FROM Sales
    ORDER BY sale_date, fruit
),
cte2 AS(
    SELECT *, 
    LEAD(sold_mun,1) OVER(PARTITION BY sale_date) AS orange_num
    FROM cte
)
SELECT sale_date, 
sold_mun - orange_num AS diff
FROM cte2
WHERE fruit = 'apples'
ORDER BY sale_date

