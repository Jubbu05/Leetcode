SELECT
  t.request_at as 'DAY',
  ROUND(SUM(IF(t.status = 'completed', 0, 1)) / COUNT(*), 2) AS 'Cancellation Rate'
FROM
  Trips t
WHERE
  (
    t.request_at BETWEEN '2013-10-01'
    AND '2013-10-03'
  )
  AND t.client_id NOT IN (
    SELECT
      users_id
    FROM
      Users
    WHERE
      banned = 'Yes'
  )
  AND t.driver_id NOT IN (
    SELECT
      users_id
    FROM
      Users
    WHERE
      banned = 'Yes'
  )
GROUP BY
  t.request_at