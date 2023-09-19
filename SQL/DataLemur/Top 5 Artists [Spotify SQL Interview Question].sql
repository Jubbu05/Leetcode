WITH top_10 AS (
  SELECT 
    artists.artist_name, 
    DENSE_RANK() OVER(ORDER BY count(songs.artist_id) DESC) AS artist_rank
  FROM
    artists
  INNER JOIN songs 
    ON artists.artist_id = songs.artist_id
  INNER JOIN global_song_rank ranking 
    ON songs.song_id =ranking.song_id
  WHERE 
    ranking.rank <=10
  GROUP BY 
    artists.artist_name
)

SELECT 
  artist_name,
  artist_rank
FROM 
  top_10 
WHERE 
  artist_rank <=5 
ORDER BY 
  artist_rank,artist_name
