SELECT 
  app_id,
  ROUND(100.0 * sum(case WHEN event_type = 'click' then 1 ELSE 0 END) / 
       sum(case WHEN event_type = 'impression' then 1 ELSE 0 END),2) as ctr
FROM events
WHERE timestamp BETWEEN '2022-01-01' AND '2022-12-31'
GROUP BY 1;