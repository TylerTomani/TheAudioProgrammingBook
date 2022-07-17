const playBtns = document.querySelectorAll(".play-btn");
const videoContainer = document.querySelector(".video-container")
const body = document.querySelector('body')
let playToggle = false;
let fullScreen = false;
playBtns.forEach(playBtn =>{
    const parent = playBtn.parentElement;
    const video = parent.querySelector("video");
    playBtn.addEventListener("click", e => {
        if(!playToggle){
            video.play();
        } else video.pause();
        playToggle = !playToggle;
    })

    playBtn.addEventListener("keydown", e => {
        let key = e.key;
        console.log(key)
        if(key === 'f' || key === 'F' && !fullScreen){
            if(!fullScreen){
                videoContainer.classList.add("video-enlarge")
                console.log(body)
                body.classList.add("background-grey")
            } else {
                videoContainer.classList.remove("video-enlarge")
                body.classList.remove("background-grey")
            }
            fullScreen = !fullScreen;
        }
    })
})
