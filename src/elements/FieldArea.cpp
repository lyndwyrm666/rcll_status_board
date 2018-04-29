/*
The MIT License (MIT)

Copyright (c) 2017-2018 Florian Eith <florian.eith@web.de>

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include <FieldArea.h>
// FieldArea ####################################################################

rcll_draw::FieldArea::FieldArea(){
    hsp_gameinfo = HStatusPanel();
    thp_team_cyan = TeamHeaderPanel();
    thp_team_magenta = TeamHeaderPanel();
    gf_gamefield = GameField();

    blbl_text.setContent("first icon: reported position    second icon: reported orientation");
    blbl_text.setAlignment(rcll_draw::Alignment::CenterCenter);
    blbl_text.setBackgroundColor(rcll_draw::C_WHITE);
    blbl_text.setBorderColor(rcll_draw::C_WHITE);
    blbl_text.setFontSize(1.0);
}

rcll_draw::FieldArea::~FieldArea(){

}

void rcll_draw::FieldArea::setGeometry(int x, int y, int w, int h, int gapsize){
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
    hsp_gameinfo.setGeometry(x + w * 0.2, y, w * 0.6, h * 0.1);
    thp_team_cyan.setGeometry(x, y, w * 0.2, h * 0.1);
    thp_team_magenta.setGeometry(x + w * 0.8, y, w * 0.2, h * 0.1);
    gf_gamefield.setGeometry(x, y + h * 0.1 + gapsize, w, h * 0.9 - gapsize);
    blbl_text.setSize(w, h * 0.1);
    blbl_text.setPos(x, y + h - gapsize);
}

void rcll_draw::FieldArea::setRefBoxView(bool refbox_view){
    gf_gamefield.setRefBoxView(refbox_view);
}

void rcll_draw::FieldArea::setGameInfo(rcll_vis_msgs::GameInfo &gameinfo){
    hsp_gameinfo.setContent(gameinfo);
    thp_team_cyan.setTeam(gameinfo.team_name_cyan, rcll_draw::CYAN);
    thp_team_magenta.setTeam(gameinfo.team_name_magenta, rcll_draw::MAGENTA);
    this->gamephase = (rcll_draw::GamePhase)gameinfo.game_phase;
    gf_gamefield.setPhase((rcll_draw::GamePhase)gameinfo.game_phase);
}

void rcll_draw::FieldArea::setGameField(rcll_vis_msgs::SetGameField &setgamefield){
    gf_gamefield.setGameField(setgamefield);
}

void rcll_draw::FieldArea::setRobots(std::vector<rcll_vis_msgs::Robot> &robots){
    return gf_gamefield.setRobots(robots);
}

void rcll_draw::FieldArea::setMachines(std::vector<rcll_vis_msgs::Machine> &machines){
    return gf_gamefield.setMachines(machines);
}

void rcll_draw::FieldArea::draw(cv::Mat &mat){
    hsp_gameinfo.draw(mat);
    thp_team_cyan.draw(mat);
    thp_team_magenta.draw(mat);
    gf_gamefield.draw(mat);

    if (gamephase == rcll_draw::EXPLORATION){
        blbl_text.draw(mat);
    }
}
