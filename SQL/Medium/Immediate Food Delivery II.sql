# SELECT ROUND((AVG(CASE WHEN deli='immediate' THEN 1 ELSE 0 END))*100,2) AS immediate_percentage
# FROM(
#   SELECT 
#   IF(MIN(order_date)=customer_pref_delivery_date,'immediate','scheduled') as deli
#   FROM Delivery
#   GROUP BY customer_id 
# ) a

select 
	round(avg(order_date = customer_pref_delivery_date)*100, 2) 'immediate_percentage'
from 
	Delivery
where 
	(customer_id, order_date) in (select customer_id, min(order_date) from Delivery group by customer_id);