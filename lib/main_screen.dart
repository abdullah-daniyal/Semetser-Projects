import 'package:flutter/material.dart';
import 'package:url_launcher/url_launcher.dart';

class MainScreen extends StatefulWidget {
  const MainScreen({Key? key}) : super(key: key);

  @override
  State<MainScreen> createState() => _MainScreenState();
}

class _MainScreenState extends State<MainScreen> {
  TextEditingController phoneNumberController = TextEditingController();
  TextEditingController messageController = TextEditingController();

  // Future<void> _launchURL(String phoneNumber, String message) async {
  //   if (!await launchUrl(
  //     Uri.parse(
  //         "https//api.whatsapp.com/send/?phone=$phoneNumber&text=$message"),
  //     mode: LaunchMode.externalApplication,
  //   )) {
  //     throw "Can not launch url";
  //   }
  // }

  @override
  void dispose() {
    phoneNumberController.dispose();
    messageController.dispose();
    super.dispose();
  }

  @override
  Widget build(BuildContext context) {
    String phoneNumber = phoneNumberController.text;
    final Uri whatsapp =
        Uri.parse("https://api.whatsapp.com/send/?phone=$phoneNumber");
    return Scaffold(
      appBar: AppBar(
        title: const Text("URL Launcher"),
        centerTitle: true,
      ),
      body: Padding(
        padding:
            const EdgeInsets.all(16.0), // Adjust the padding values as needed
        child: Center(
          child: Column(
            mainAxisAlignment: MainAxisAlignment.center,
            children: [
              TextField(
                controller: phoneNumberController,
                decoration: const InputDecoration(
                  border: OutlineInputBorder(),
                  labelText: 'Enter the Phone Number',
                ),
              ),
              // const SizedBox(height: 20),
              // TextField(
              //   controller: messageController,
              //   decoration: const InputDecoration(
              //     border: OutlineInputBorder(),
              //     labelText: 'Enter any Message (Optional)',
              //   ),
              // ),

              //03336586214
              const SizedBox(height: 20),
              ElevatedButton(
                onPressed: () {
                  launchUrl(whatsapp);
                },
                child: const Text("Open WhatsApp"),
              ),
            ],
          ),
        ),
      ),
    );
  }
}
