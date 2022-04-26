# FFmpeg 命令

## 提取音视频

```ffmpeg
- ffmpeg -i input_file -vcodec copy -an output_file_video　　//分离视频流
- ffmpeg -i input_file -acodec copy -vn output_file_audio　　//分离音频流
- ffmpeg -i input.mp4 -an output.mp4             //去掉视频中的音频
- ffmpeg -i test.avi -vcodec copy -an output.avi //去掉视频中的音频
```

## 视频转码相关

```ffmpeg
- ffmpeg -i test.ts -acodec copy -vcodec copy -f mp4 output.mp4//ts视频流转mp4
- ffmpeg -i test.h264 -vcodec copy -f mpegts output.ts//h264视频转ts视频流
- ffmpeg -i test.h264 -vcodec copy -f mp4 output.mp4//h264视频转mp4
- ffmpeg -i test.mp4 -b:v 640k output.flv //mp4转flv
- ffmpeg -i test.mp4 -acodec copy -vcodec copy -f flv output.flv //mp4转flv
- ffmpeg -i test.flv -b:v 640k output.mp4 //flv转mp4
- ffmpeg -i test.mp4 -s 176x144 -vcodec h263 -r 25 -b 12200 -ab 12200 -ac 1 -ar 8000 output.3gp //mp4转3gp
- ffmpeg -i test.avi -s aqif -vcodec -acodec mp3 -ac 1 -ar 8000 -r 25 -ab 32 -y output.3gp //avi转3gp
- ffmpeg -i test.3gp -f avi -vcodec xvid -acodec mp3 -ar 22050 output.avi //3gp转flv
- ffmpeg -i test.flv -s 176x144 -vcodec h263 -r 25 -b 200 -ab 64 -acodec mp3 -ac 1 -ar 8000 output.3gp //flv转3gp
- ffmpeg -i test.mp4 output.avi //mp4转avi
- ffmpeg -i test.flv -vcodec h264 -r 25 -b 200 -ab 128 -acodec mp3 -ac 2 -ar 44100 output.mp4 //flv转mp4
- ffmpeg -i test.mp4 -c:v libx264 -ar 22050 -crf 28 output.flv //mp4转flv
- ffmpeg -i test.avi -c copy -map 0 output.mp4 //avi转mp4
- ffmpeg -i 154202543368.m3u8 -c copy -bsf:a aac_adtstoasc -movflags +faststart test.mp4 //m3u8转mp4
- ffmpeg -i test.mkv -y -vcodec copy -acodec copy output.mp4 //mkv转mp4
- ffmpeg -i test.mkv -vcodec copy -acodec copy output.avi  //mkv转avi
```

## 视频剪切

```ffmpeg
- ffmpeg -ss 10 -t 15 -i test.mp4 -codec copy cut.mp4
- ffmpeg -ss 00:05:30.0 -to 00:10:00.0 -i input.flv -c copy -avoid_negative_ts 1 output.flv
```

## 倒放音视频&加速视频&减速视频

```ffmpeg
- ffmpeg.exe -i inputfile.mp4 -filter_complex [0:v]reverse[v] -map [v] -preset superfast reversed.mp4 //视频倒放，无音频
- ffmpeg.exe -i inputfile.mp4 -vf reverse reversed.mp4//视频倒放，音频不变
- ffmpeg.exe -i inputfile.mp4 -map 0 -c:v copy -af "areverse" reversed_audio.mp4//音频倒放，视频不变
- ffmpeg.exe -i inputfile.mp4 -vf reverse -af areverse -preset superfast reversed.mp4//音视频同时倒放
- ffmpeg -i inputfile.mp4 -vf setpts=PTS/2 -af atempo=2 output.mp4//视频加速，帧速率变为2倍，调整倍速范围【0.25，4】
- ffmpeg -i input.mkv -an -filter:v "setpts=0.5*PTS" output.mkv//视频减速播放
```

## 视频拼接

```ffmpeg
- ffmpeg -f concat -i myfile.txt -c copy 111.flv
```

## 字幕压制

```ffmpeg
- ffmpeg -i input.flv -c:a copy -c:v libx264 -b:v 14M -vf subtitles=input.ass -preset 7 output.flv
- ffmpeg -i input.flv -c:a copy -c:v libx264 -crf 17 -vf subtitles=input.ass -preset 7 output.flv
```
