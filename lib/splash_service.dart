import 'dart:async';

import 'package:flutter/material.dart';
import 'package:newurllauncher/main_screen.dart';

class SplashServices {
  void isLogin(BuildContext context) {
    Timer(
        const Duration(seconds: 3),
        () => Navigator.push(context,
            MaterialPageRoute(builder: (context) => const MainScreen())));
  }
}
