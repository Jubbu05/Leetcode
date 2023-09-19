SELECT t1.page_id
FROM pages AS t1
WHERE t1.page_id NOT IN (SELECT page_id FROM page_likes)
ORDER BY 1

----------------------------------------------------------

SELECT p.page_id
FROM pages AS p
LEFT JOIN page_likes AS pl
ON p.page_id = pl.page_id
WHERE pl.liked_date is NULL
ORDER BY 1

