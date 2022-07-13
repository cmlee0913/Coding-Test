setCollideScene(true);
playAnimation("fly",true)

onKey("right",function(){
   setVelocityX(500)
})
onKey("left",function(){
    setVelocityX(-500)
})

onKeyUp("left",function(){
    setVelocityX(0)
})
onKeyUp("right",function(){
    setVelocityX(0)
})

onOverlap(["effect_beam_f","effect_beam_f(2)", "effect_beam_f(3)", "effect_beam_f(4)", "effect_beam_f(5)", "effect_beam_f(6)", "little_ghost_a"],function(){
    changeScene("scene3")
    global.score = getTimer();
    pauseTimer();
})