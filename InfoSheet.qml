/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the Qt3D module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

import QtQuick 2.0

Rectangle {
    id: infoSheet

    width: 200
    height: 450
    anchors.verticalCenter: parent.verticalCenter

    property alias planet: planetText.planet
    property alias radius: infoText.radius
    property alias temperature: infoText.temperature
    property alias orbitalPeriod: infoText.orbitalPeriod
    property alias distance: infoText.distance

    property alias weight: weightText.weight //-------------------------------------------------------
    property alias mass: weightText.mass //-------------------------------------------------------------

    property alias exampleDetails: infoText.exampleDetails

    Behavior on opacity { PropertyAnimation {} }

    color: "transparent"

    Text {
        id: planetText
        anchors.top: parent.top
        anchors.topMargin: 20
        anchors.horizontalCenter: parent.horizontalCenter

        property string planet: ""

        font.family: "Helvetica"
        font.pixelSize: 32
        font.weight: Font.Light
        color: "white"

        text: "<p>" + planet + "</p>"
    }
    Text {
        id: infoText
        anchors.top: planetText.bottom
        anchors.horizontalCenter: parent.horizontalCenter

        property string radius: ""
        property string temperature: ""
        property string orbitalPeriod: ""
        property string distance: ""
        property string exampleDetails: ""

        font.family: "Helvetica"
        font.pixelSize: 18
        font.weight: Font.Light
        lineHeight: 1.625 * 18
        lineHeightMode: Text.FixedHeight
        color: "white"

        text: {
            if (planet == "Układ Słoneczny") {
                "<p>" + exampleDetails + "</p>"
            } else if (planet == "Słońce") {
                "<p>Średnica równikowa:</p><p>" + radius + "</p></br>"
                + "<p>Temperatura powiechrzni:</p><p>" + temperature + "</p>"

            } else if (planet == "Księżyc"){
                "<p>Średnica równikowa:</p><p>" + radius + "</p></br>"
                + "<p>Temperatura powierzchni:</p><p>" + temperature + "</p></br>"
                + "<p>Okres obrotu wokół Ziemi:</p><p>" + orbitalPeriod + "</p></br>"
                + "<p>Odległość od Ziemi:</p><p>" + distance + "</p></br>"
            }
            else {
                "<p>Średnica równikowa:</p><p>" + radius + "</p></br>"
                + "<p>Temperatura powierzchni:</p><p>" + temperature + "</p></br>"
                + "<p>Okres obrotu wokół Słońca:</p><p>" + orbitalPeriod + "</p></br>"
                + "<p>Odległość od Słońca:</p><p>" + distance + "</p></br>"
            }
        }

        onLinkActivated: Qt.openUrlExternally(link)
    }
    //===================================================================================
    Text {
        id: weightText
        anchors.top: parent.top
        //anchors.topMargin: 100
        anchors.left: parent.left
        anchors.leftMargin: 1350
        //anchors.horizontalCenter: parent.horizontalCenter

        property string weight: ""
        property string mass: ""

        font.family: "Helvetica"
        font.pixelSize: 22
        font.weight: Font.Light
        lineHeight: 1.625 * 30
        lineHeightMode: Text.FixedHeight
        color: "white"

        text: {
            if(planet == "Układ Słoneczny"){
                ""
            }
            else if(planet == "Słońce"){
                "<p>Twoja masa wynosi: " +  mass + "</p><p>"
                 +"<p>Twój ciężar na Słońcu wynosi:</p><p>" + weight +"</p></br></br>"
            } else if(planet == "Merkury"){
                "<p>Twoja masa wynosi: " +  mass + "</p><p>"
                 +"<p>Twój ciężar na Merkurym wynosi:</p><p>" + weight +"</p></br></br>"
            } else if(planet == "Wenus"){
                "<p>Twoja masa wynosi: " +  mass + "</p><p>"
                 +"<p>Twój ciężar na Wenus wynosi:</p><p>" + weight +"</p></br></br>"
            } else if(planet == "Ziemia"){
                "<p>Twoja masa wynosi: " +  mass + "</p><p>"
                +"<p>Twój ciężar na Ziemi wynosi:</p><p>" + weight +"</p></br></br>"
            } else if(planet == "Mars"){
                "<p>Twoja masa wynosi: " +  mass + "</p><p>"
                +"<p>Twój ciężar na Marsie wynosi:</p><p>" + weight +"</p></br></br>"
            } else if(planet == "Jowisz"){
                "<p>Twoja masa wynosi: " +  mass + "</p><p>"
                +"<p>Twój ciężar na Jowiszu wynosi:</p><p>" + weight +"</p></br></br>"
            } else if(planet == "Saturn"){
                "<p>Twoja masa wynosi: " +  mass + "</p><p>"
                +"<p>Twój ciężar na Saturnie wynosi:</p><p>" + weight +"</p></br></br>"
            } else if(planet == "Uran"){
                "<p>Twoja masa wynosi: " +  mass + "</p><p>"
                +"<p>Twój ciężar na Uranie wynosi:</p><p>" + weight +"</p></br></br>"
            } else if(planet == "Neptun"){
                "<p>Twoja masa wynosi: " +  mass + "</p><p>"
                +"<p>Twój ciężar na Neptunie wynosi:</p><p>" + weight +"</p></br></br>"
            } else if(planet == "Księżyc"){
                "<p>Twoja masa wynosi: " +  mass + "</p><p>"
                +"<p>Twój ciężar na Księżycu wynosi:</p><p>" + weight +"</p></br></br>"
            }
        }
    }
    //===========================================================================================
}

