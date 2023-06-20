SELECT i.item_category AS category,
SUM(CASE WHEN DAYOFWEEK(o.order_date) = 1 THEN 1 ELSE 0 END) AS 'Sunday',
SUM(CASE WHEN DAYOFWEEK(o.order_date) = 2 THEN 1 ELSE 0 END) AS 'Monday',
SUM(CASE WHEN DAYOFWEEK(o.order_date) = 3 THEN 1 ELSE 0 END) AS 'Tuesday',
SUM(CASE WHEN DAYOFWEEK(o.order_date) = 4 THEN 1 ELSE 0 END) AS 'Wednesday',
SUM(CASE WHEN DAYOFWEEK(o.order_date) = 5 THEN 1 ELSE 0 END) AS 'Thursday',
SUM(CASE WHEN DAYOFWEEK(o.order_date) = 6 THEN 1 ELSE 0 END) AS 'Friday',
SUM(CASE WHEN DAYOFWEEK(o.order_date) = 7 THEN 1 ELSE 0 END) AS 'Saturday'
FROM items i
LEFT JOIN orders o
ON i.item_id = o.item_id
GROUP BY i.item_category