// SPDX-License-Identifier: MIT

ThisBuild / scalaVersion     := "2.13.10"
ThisBuild / version          := "0.1.0"
ThisBuild / organization     := "dev.leorium"

val chiselVersion = "3.6.1"

lazy val root = (project in file("."))
  .settings(
    name := "chisel-tpu",
    libraryDependencies ++= Seq(
      "edu.berkeley.cs" %% "chisel3" % chiselVersion,
      "edu.berkeley.cs" %% "chiseltest" % "0.6.0" % "test",
      "edu.berkeley.cs" %% "firrtl" % "1.6.0",
    ),
    scalacOptions ++= Seq(
      "-language:reflectiveCalls",
      "-feature",
      "-Xcheckinit",
      "-Wconf:cat=deprecation:s",
    ),
    addCompilerPlugin("edu.berkeley.cs" % "chisel3-plugin" % chiselVersion cross CrossVersion.full),
    Test / fork := true,
  )
