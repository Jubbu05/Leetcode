SELECT manufacturer,
('$' || round(sum(total_sales)/ 1000000) || ' million') as sale
FROM pharmacy_sales
group by 1 
ORDER BY SUM(total_sales) desc