/****************************************************************************
**
** Copyright (C) 2014 Klaralvdalens Datakonsult AB (KDAB).
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


import Qt3D.Core 2.0
import Qt3D.Render 2.0
import QtQuick 2.1

Material {
    id: root
    property color ambientLight: Qt.rgba(0.1, 0.1, 0.1, 1.0)
    property color diffuseColor: Qt.rgba(0.7, 0.7, 0.7, 1.0)
    property color specularColor: Qt.rgba(0.5, 0.5, 0.5, 1.0)
    property real shininess: 150.0
    property string diffuseMap
    property string specularMap
    property string normalMap
    property real textureScale: 1.0
    property real opacity: 1.0

    parameters: [
        Parameter {
            name: "ambient"
            value: Qt.vector3d(root.ambientLight.r, root.ambientLight.g, root.ambientLight.b)
        },
        Parameter {
            name: "diffuse"
            value: Qt.vector3d(root.diffuseColor.r, root.diffuseColor.g, root.diffuseColor.b)
        },
        Parameter {
            name: "specular"
            value: Qt.vector3d(root.specularColor.r, root.specularColor.g, root.specularColor.b)
        },
        Parameter {
            name: "shininess"
            value: root.shininess
        },
        Parameter {
            name: "diffuseTexture"
            value: Texture2D {
                id: diffuseTexture
                minificationFilter: Texture.LinearMipMapLinear
                magnificationFilter: Texture.Linear
                wrapMode {
                    x: WrapMode.Repeat
                    y: WrapMode.Repeat
                }
                generateMipMaps: true
                maximumAnisotropy: 16.0
                TextureImage {
                    id: diffuseTextureImage
                    source: diffuseMap
                }
            }
        },
        Parameter {
            name: "specularTexture"
            value: Texture2D {
                id: specularTexture
                minificationFilter: Texture.LinearMipMapLinear
                magnificationFilter: Texture.Linear
                wrapMode {
                    x: WrapMode.Repeat
                    y: WrapMode.Repeat
                }
                generateMipMaps: true
                maximumAnisotropy: 16.0
                TextureImage {
                    id: specularTextureImage
                    // Get rid of runtime warnings. It's safe, as the texture just isn't used
                    source: specularMap !== "" ? specularMap
                                               : "qrc:/images/solarsystemscope/uranusmap.jpg"
                }
            }
        },
        Parameter {
            name: "normalTexture"
            value: Texture2D {
                id: normalTexture
                minificationFilter: Texture.Linear
                magnificationFilter: Texture.Linear
                wrapMode {
                    x: WrapMode.Repeat
                    y: WrapMode.Repeat
                }
                maximumAnisotropy: 16.0
                TextureImage {
                    id: normalTextureImage
                    // Get rid of runtime warnings. It's safe, as the texture just isn't used
                    source: normalMap !== "" ? normalMap
                                             : "qrc:/images/solarsystemscope/uranusmap.jpg"
                }
            }
        },
        Parameter {
            name: "texCoordScale"
            value: textureScale
        },
        Parameter {
            name: "opacity"
            value: opacity
        }
    ]
}
