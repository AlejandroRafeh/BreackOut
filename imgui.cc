

void HandelImgui(Ball *ball){
    if(ball == nullptr)return;
    ImGui::Begin("ImGui example");
    ImVec4 color = { 1.0f, 0.0f, 0.0f, 1.0f };
    ImGui::TextColored(color, "Direction: ");
    ImGui::SliderFloat("float", &ball->direction.x,-300.0f, 300.0f); 
    ImGui::SliderFloat("float", &ball->direction.y,-300.0f, 300.0f); 

    //ImGui::DragFloat2("Position: ", &g_square.pos.x, 1.0f, 0.0f, kWindowHeight);

    ImGui::End();

}