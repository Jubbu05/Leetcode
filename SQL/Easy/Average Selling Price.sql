SELECT p.product_id,
ROUND (SUM(s.units*p.price)/SUM(s.units),2) as average_price
FROM Prices p
JOIN UnitsSold s
ON p.product_id=s.product_id AND (s.purchase_date BETWEEN p.start_date AND p.end_date)
GROUP BY product_id;