# 조회수가 가장 높은 중고거래 게시물에 대한 첨부파일 경로를 조회
select concat('/home/grep/src/', B.BOARD_ID, '/', F.FILE_ID, F.FILE_NAME, F.FILE_EXT) as FILE_PATH
from USED_GOODS_BOARD B
join USED_GOODS_FILE F on F.BOARD_ID=B.BOARD_ID
where B.VIEWS = (
    select max(views)
    from USED_GOODS_BOARD
)
order by FILE_ID desc;